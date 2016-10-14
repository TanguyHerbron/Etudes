#include <stdio.h>
#include <stdlib.h>

int main()
{
    float note;

    printf("Entrer la note obtenue :");
    scanf("%f", &note);
    if(note >= 16){
        printf("Votre note est A.\n");
    }else{
     if(note >= 12){
        printf("Votre note est B.\n");
    }else{
     if(note >= 8){
        printf("Votre note est C.\n");
    }else{
     if(note >= 4){
        printf("Votre note est D.\n");
    }else{
        printf("Votre note est E.\n");
    }}}}

    return 0;
}
