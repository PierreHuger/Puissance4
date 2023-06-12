#include <stdio.h>
#include <stdlib.h>

const char PION_A='X';
const char PION_B='O';
const char VIDE='_';
const char INCONNU= ' ';
const int NLIG= 6;
const int NCOL= 7;
const int COLONNE_DEBUT= 3;
const int TAB_PLEIN =42;

#define NBLIG 6
#define NBCOL 7;

typedef char Grille[NBLIG][NBCOL];
typedef char tab[NBCOl]

int main()
{
    int i;

    for(i=0;i<NBLIG;i++)
    {
        if (joueur==0)
        {
            pion=PION_A;
            joueur=joueur+1;
        }
        else if (joueur==1)
        {
            pion=PION_B;
            joueur=joueur-1;
        }
    }
}

void afficher(Grille g, tab t, char pion, int colonne)
{
    int i, j;

    system("clear");
    system("cls");
    
    for(i=0;i<NBCOL;i++)
    {
        if(i!=colonne)
        {
            printf("%c", t[i]);
        }
        else if(i==colonne)
        {
            t[i]=pion;
            printf("%c", t[i]);
        }
    }

    for(i=0;i<NBLIG;i++)
    {
        for(j=0;j<NBCOL;j++)
        {
            printf(" %c", g[j][i]);
        }
        printf("\n");
    }

}