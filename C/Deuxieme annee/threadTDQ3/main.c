#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

typedef struct {
	int v1;
	int v2;
	int v3;
}laStruct;

laStruct maStruct;

pthread_mutex_t mutex;

void *fonction_update (int val[])
{
    pthread_mutex_lock(&mutex);
    maStruct.v1 = val[0];
    maStruct.v2 = val[1];
    maStruct.v3 = val[2];
    printf("Valeur en cours de Thread :\n\t%d\t%d\t%d\n\n",maStruct.v1, maStruct.v2, maStruct.v3);
    pthread_mutex_unlock(&mutex);
}

int main()
{
    pthread_t un_thread;
    pthread_t deux_thread;
    pthread_t trois_thread;

    void *thread_result;
    int resultat;
    int valT1[3] = {1, 3, 5};
    int valT2[3] = {2, 4, 6};
    int valT3[3] = {10, 20, 30};
    int retourMutex;
    pthread_mutexattr_t mutexattr = PTHREAD_MUTEX_INITIALIZER;

    retourMutex = pthread_mutex_init(&mutex, &mutexattr);
    if (retourMutex != 0)
    {
        perror("Erreur peu probable dans l'initialisation du mutex.");
        exit(EXIT_FAILURE);
    }

    resultat = pthread_create(&un_thread, NULL, fonction_update, (void *) valT1);
    if (resultat != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }

    printf("Attente de la fin du thread...\n");

    resultat = pthread_create(&deux_thread, NULL, fonction_update, (void *) valT2);
    if (resultat != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }

    printf("Attente de la fin du thread...\n");


    resultat = pthread_create(&trois_thread, NULL, fonction_update, (void *) valT3);
    if (resultat != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }

    printf("Attente de la fin du thread...\n");

	resultat = pthread_join(un_thread, &thread_result);
    if (resultat != 0) {
        perror("Thread join a foir... echoué");
        exit(EXIT_FAILURE);
    }

	resultat = pthread_join(deux_thread, &thread_result);
    if (resultat != 0) {
        perror("Thread join a foir... echoué");
        exit(EXIT_FAILURE);
    }

	resultat = pthread_join(trois_thread, &thread_result);
    if (resultat != 0) {
        perror("Thread join a foir... echoué");
        exit(EXIT_FAILURE);
    }

    pthread_mutex_lock(&mutex);
    printf("Val finale :\n\t%d\t%d\t%d\n", maStruct.v1, maStruct.v2, maStruct.v3);
    pthread_mutex_unlock(&mutex);
    exit(EXIT_SUCCESS);
    return 0;
}
