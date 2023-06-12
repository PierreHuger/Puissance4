#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

const char PION_A='X'; //joueur 1
const char PION_B='O'; //joueur 2
const char VIDE='_';
const char INCONNU= ' ';
const int NBLIG= 6; //Nombre de lignes
const int NBCOL= 7; //Nombre de colonnes
const int COLONNE_DEBUT= 3;  //colonne de debut pour commencer au milieu du tableau pour choisirColonne
const int LIG_DEBUT=5; //Ligne de debut, Permet de commencer en bas du tableau
bool Debut=true;

#define NBLIG 6
#define NBCOL 7

typedef char Grille[NBLIG][NBCOL];

void initGrille(Grille);
void afficher(Grille, char, int);
bool grillePleine(Grille);
void jouer(Grille, char, int *, int *); 
int choisirColonne(Grille, char, int);
int trouverLigne(Grille, int);
bool estVainqueur(Grille, int, int);
void finDePartie(char);

int main()
{
    Grille tab;

    grillePleine(tab);
}

bool grillePleine(Grille g)
{
    int i, j;
    bool res;

    i=0;
    j=0;
    res=true;
    
    /*Cette boucle permet de vérifier si la Grille est pleine ou pas*/
    while(res&&(i<NBLIG-1))
    {
        while(res&&(j<NBCOL-1))
        {
            if(g[i][j]==VIDE)
            {
                res=false;
            }
            j++;
        }
        i++;
    }

    printf("%B", res);
    return res;
}
