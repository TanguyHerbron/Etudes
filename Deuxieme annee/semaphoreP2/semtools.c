/******************************************************
Fichier : semtools.c
Boite a outils pour manipuler des semaphores
******************************************************/

#include "semtools.h"

int fixe_valeursem(){
	union semun sem_union;
	sem_union.val = 1;
	int retour = 1;
	printf("id_sem dans fixe_valeur = %d\n",id_sem);
	if (semctl(id_sem,0,SETVAL,/*sem_union*/1) == -1){
		printf("impossible de creer le semaphore\n%s\n",strerror(errno));
		retour = 0;
	}
	return(retour);
}

void supp_valeursem(){
	union semun sem_union;

	if (semctl(id_sem,0,IPC_RMID,sem_union) == -1){
		printf("impossible de supprimer le semaphore\n%s\n",strerror(errno));
	}
}



int P(){
	struct sembuf sem_b;
	int retour = 1;
	sem_b.sem_num = 0;
	sem_b.sem_op = -1;	//P()
	sem_b.sem_flg = SEM_UNDO ;
	if (semop(id_sem,&sem_b,1) == -1){
		printf("echec semaphore P()\n%s\n",strerror(errno));
		retour = 0 ;
	}
	return(retour);
}

int V(){
	struct sembuf sem_b;
	int retour=1;

	sem_b.sem_num = 0;
	sem_b.sem_op = 1;	//V()
	sem_b.sem_flg = SEM_UNDO ;
	if (semop(id_sem,&sem_b,1) == -1){
		printf("echec semaphore V()\n%s\n",strerror(errno));
		retour = 0 ;
	}
	return(retour);
}

