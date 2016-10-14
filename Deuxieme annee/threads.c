#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/syscall.h>

char message[255];

typedef struct {
	int v1;
	int v2;
	int v3;
}laStruct;

void *ma_fonction_thread(void *arg)
{
    int tid = syscall(SYS_gettid);
    printf("Le tid du thread est :%d\n", tid);
    sleep(3);
    strcpy(message, "Bye!");
    pthread_exit((void *) "Merci pour le temps CPU.");
}

int main()
{
    int resultat;
    pthread_t un_thread;
    void *thread_result;

    strcpy(message, "Debian c'est cool.");

    resultat = pthread_create(&un_thread, NULL, ma_fonction_thread, (void *)message);

    if (resultat != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    printf("PID du programme principal : %d\n", getpid());
    printf("Attente de la fin du thread...\n");

	resultat = pthread_join(un_thread, &thread_result);
    if (resultat != 0) {
        perror("Thread join a foir... echoué");
        exit(EXIT_FAILURE);
    }

    printf("OK, valeur de retour du Thread join :%s\n", (char *)thread_result);
    printf("Le message est maintenant %s\n", message);
    exit(EXIT_SUCCESS);
}
