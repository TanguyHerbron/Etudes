#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    float val1, val2;
    char car1;

    if(argc < 4){
        exit(0);
    }

    sscanf(argv[1], "%c", &car1);
    sscanf(argv[2], "%f", &val1);
    sscanf(argv[3], "%f", &val2);

    switch (car1){
    case '+':
        printf("%f\n", val1 + val2);
        break;
    case '*':
        printf("%f\n", val1 * val2);
        break;
    case '/':
        printf("%f\n", val1 / val2);
        break;
    case '-':
        printf("%f\n", val1 - val2);
        break;
    default:
        printf("Non\n");
        break;
    }

    return 0;
}
