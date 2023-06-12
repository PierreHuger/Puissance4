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
const int LIG_DEBUT=5;

#define NBLIG 6
#define NBCOL 7

typedef char Grille[NBLIG][NBCOL];
typedef char tab[NBCOL];

int choisirColonne(Grille, tab, char, int);
void initGrille(Grille);
void afficher(Grille, tab, char, int);
int trouverLigne(Grille g, int colonne, int *a)

int main()
{
    tab t;
    
    Grille tab;
    int i;
    char pion;
    int Case, joueur;

    initGrille(tab);
    
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

        choisirColonne(tab, t, pion, Case);
    }
}

int trouverLigne(Grille g, int colonne)
{
    int i, resultat;
    i=LIG_DEBUT;
    resultat=-1;

    while((resultat==-1)&&(i>0))
    {
        if(g[i][colonne]==VIDE))
        {
            resultat=i;
        }
        else //g[i][colonne]!=VIDE 
        {
            i=i-1;
        }
    }
        

    return resultat;
}