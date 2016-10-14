#include "biblio.h"

int main(int argc, char *argv[])
{
    if(argc == 4)
    {
        if(strcmp(argv[1], "d") == 0)
        {
            decompressBMP(argv[2], argv[3]);
        }

        if(strcmp(argv[1], "c") == 0)
        {
            compressBMP(argv[2], argv[3]);
        }
    }
}
