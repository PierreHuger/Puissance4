#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const char PION_A='X';
const char PION_B='O';
const char VIDE='_';
const char INCONNU= ' ';
const int NBLIG= 6;
const int NBCOL= 7;
const int COLONNE_DEBUT= 4;
const int TAB_PLEIN =42;

#define NBLIG 6
#define NBCOL 7

typedef char Grille[NBLIG][NBCOL];

void initGrille(Grille);

int main()
{
    Grille tab;
    int i, j;

    initGrille(tab);

    for(i=0;i<NBLIG;i++)
    {
        for(j=0;j<NBCOL;j++)
        {
            printf(" %c", tab[i][j]);
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}

void initGrille(Grille g)
{
    int i, j;

    for(i=0;i<NBLIG;i++)
    {
        for(j=0;j<NBCOL;j++)
        {
            g[i][j]='_';
        }
    }

}

