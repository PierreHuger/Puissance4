#include <stdio.h>
#include <stdlib.h>

const int NBLIG= 6;
const int NBCOL= 7;
const char VIDE='_';


int main()
{
    char Grille[NBLIG-1][NBCOL-1];

    Grille[NBLIG-1][NBCOL-1]={'_'};

    printf("%c\n", Grille[]);
    
    return EXIT_SUCCESS;
}