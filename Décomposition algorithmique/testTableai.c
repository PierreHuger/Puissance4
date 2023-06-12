#include <stdio.h>
#include <stdlib.h>

const int NBLIG= 6;
const int NBCOL= 7;
typedef char Grille[NBLIG-1][NBCOL-1];

int main()
{
    int i;
    char Grille[NBLIG-1][NBCOL-1]={'_'};

    printf("%s\n", Grille);
    
    return EXIT_SUCCESS;
}