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

void *fonction_update1 (int val)
{
    maStruct.v1 = val;
}

void *fonction_update2 (int val)
{
    maStruct.v2 = val;
}

void *fonction_update3 (int val)
{
    maStruct.v3 = val;
}

int main()
{
    int resultat;
    pthread_t un_thread;
    pthread_t deux_thread;
    pthread_t trois_thread;
    void *thread_result;
    int val[3] = {1, 3, 5};

    resultat = pthread_create(&un_thread, NULL, fonction_update1, (void *) val[0]);

    if (resultat != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }

    resultat = pthread_create(&deux_thread, NULL, fonction_update2, (void *) val[1]);

    if (resultat != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }

    resultat = pthread_create(&trois_thread, NULL, fonction_update3, (void *) val[2]);

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
