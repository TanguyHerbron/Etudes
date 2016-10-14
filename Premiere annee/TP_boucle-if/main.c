#include <stdio.h>
#include <stdlib.h>

int main()
{
    char note;

    printf("Entrer la note en minuscule:");
    scanf("%c", &note);
    if(note == 'a'){
        printf("Votre note est entre 16 et 20.\n");
    }else{
        if(note == 'b'){
            printf("Votre note est entre 12 et 16.\n");
        }else{
            if(note == 'c'){
                printf("Votre note est entre 8 et 12.\n");
            }else{
                if(note == 'd'){
                    printf("Votre note est entre 4 et 8.\n");
                }else{
                    if(note == 'e'){                        printf("Votre note est entre 0 et 4.\n");
                    }
                }
            }
        }
    }


}
