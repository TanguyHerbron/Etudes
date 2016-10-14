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

void *fonction_update1 ()
{
    maStruct.v1 = 1;
}

void *fonction_update2 ()
{
    maStruct.v2 = 2;
}

void *fonction_update3 ()
{
    maStruct.v3 = 3;
}

int main()
{
    int resultat;
    pthread_t un_thread;
    pthread_t deux_thread;
    pthread_t trois_thread;
    void *thread_result;

    resultat = pthread_create(&un_thread, NULL, fonction_update1, NULL);

    if (resultat != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }

    resultat = pthread_create(&deux_thread, NULL, fonction_update2, NULL);

    if (resultat != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }

    resultat = pthread_create(&trois_thread, NULL, fonction_update3, NULL);

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

    printf("Attente de la fin du thread...\n");

	resultat = pthread_join(deux_thread, &thread_result);
    if (resultat != 0) {
        perror("Thread join a foir... echoué");
        exit(EXIT_FAILURE);
    }

    printf("Attente de la fin du thread...\n");

	resultat = pthread_join(trois_thread, &thread_result);
    if (resultat != 0) {
        perror("Thread join a foir... echoué");
        exit(EXIT_FAILURE);
    }

    printf("%d\n%d\n%d\n", maStruct.v1, maStruct.v2, maStruct.v3);
    exit(EXIT_SUCCESS);
    return 0;
}
