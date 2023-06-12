#include <stdio.h>
#include <stdlib.h>

const char PION_A='X';
const char PION_B='O';
const char VIDE='_';
const char INCONNU= ' ';
const int NBLIG= 6;
const int NBCOL= 7;
const int COLONNE_DEBUT= 3;
const int TAB_PLEIN =42;

#define NBLIG 6
#define NBCOL 7

typedef char Grille[NBLIG][NBCOL];

int choisirColonne(Grille, char, int);
void initGrille(Grille);
void afficher(Grille, char, int);

int main()
{
    
    Grille Puissance4;
    int i;
    char pion;
    int Case, joueur;

    initGrille(Puissance4);

    joueur=0;
    Case=COLONNE_DEBUT;
    
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

        choisirColonne(Puissance4, pion, Case);
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
            g[i][j]=VIDE;
        }
    }

}

int choisirColonne(Grille t, char pion, int colonne)
{
    char deplacement, poubelle;
    int indice_col;

    indice_col=colonne;
    
    afficher(t, pion, indice_col);

    printf("Deplacement a gauche ou a droite ? (q/d)\n");
    scanf("%c%c", &deplacement, &poubelle);      

    do
    {

        if((indice_col<=NBCOL)&&(indice_col>=0))
        {
            if((deplacement=='q')&&(indice_col>0))
            {
                indice_col=indice_col-1;
            }
            else if((deplacement=='d')&&(indice_col<NBCOL-1))
            {
                indice_col=indice_col+1;
            }
        }
    
        afficher(t, pion, indice_col);

        printf("Deplacement a gauche ou a droite ? (q/d)\n");
        scanf("%c%c", &deplacement, &poubelle);        

    }while(deplacement!=INCONNU);

    return indice_col;
}


void afficher(Grille g, char pion, int colonne)
{
    int i, j;

    for(i=0;i<NBCOL;i++)
    {
        if(i!=colonne)
        {
            if((i==0)||(i==NBCOL-1))
            {
                printf("    ");
            }
            else
            {
                printf("    ");
            }
        }
        else if(i==colonne)
        {
            printf("  %c", pion);
        }
    }

    printf("\n");

    for(i=0;i<NBLIG;i++)
    {
        for(j=0;j<NBCOL;j++)
        {
            if(j==0)
            {
                printf("| %c |", g[i][j]);
            }
            else
            {
                printf(" %c |", g[i][j]);
            }
        }
        printf("\n");
        printf("\n");
    }

}

