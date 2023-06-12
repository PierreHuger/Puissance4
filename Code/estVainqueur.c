#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const char PION_A='X';
const char PION_B='O';
const char VIDE='_';
const char INCONNU= ' ';
const int NBLIG= 6;
const int NBCOL= 7;
const int COLONNE_DEBUT= 3;
const int LIG_DEBUT=5;
const int TAB_PLEIN =42;

#define NBLIG 6
#define NBCOL 7

typedef char Grille[NBLIG][NBCOL];

bool estVainqueur(Grille g, int ligne, int colonne)
{   
    int res, total, compteur, lig, col, diagonaleGauche, diagonaleDroite;
    char pion;

    lig=ligne;
    col=colonne;
    res=false;
    total=1;
    pion=g[ligne][colonne];

    /*Cette boucle permet de vérifier si 4 jetons sont alignés sur une ligne*/
    
    /*Vers la droite*/
    while (g[lig][col]==pion && col<NBCOL-1 && total!=4)
    {
        total++;
        col++;
    }

    col=colonne;

    /*Vers la gauche*/
    while (g[lig][col]==pion && col>0 && tota!=4)
    {
        total++;
        col--;
    }

    //attribue vrai au resultat si 4 jetons sont alignés 
    if(total==4)
    {
        res=true;
    }

    total=1;
    
    if(res==false) //permet d'éviter de faire les vérifications si le res est vrai car cela veut dire qu'il y a un vainqueur
    {
        col=colonne;
        /*Cette boucle permet de vérifier si 4 jetons sont alignés en colonne*/

        /*Vers le haut*/
        while ((g[lig][col]==pion) && lig>0 && total!=4)
        {
            total++;
            lig--;
        }

        lig=ligne;
        
        /*Vers le bas*/
        while ((g[lig][col]==pion) && lig<NBLIG && total!=4)
        {
            total++;
            lig++;
        }

        /*attribue vrai au resultat si 4 jetons sont alignés*/ 
        if(total==4)
        {
            res=true;
        }

        lig=ligne;
        total=1;

        if(res==false)
        {
            /*Cette boucle permet de vérifier si 4 jetons sont alignés sur la diagonale gauche*/
            
            /*Vers le haut*/
            while ((g[lig][col]==pion) && lig<5 && col<NBCOL-1 && total!=4)
            {
                lig--;
                col++;
                total++;
            }
            
            /*Vers le bas*/
            while ((g[lig][col]==pion) && lig<5 && col<NBCOL-1 && total!=4)
            {
                lig++;
                col--;
                total++;
            }

            if(res==false)
            {
                /*Cette boucle permet de vérifier si 4 jetons sont alignés sur la diagonale droite*/
                
                /*Vers le haut*/
                while ((g[lig][col]==pion) && lig<5 && col<NBCOL-1 && total!=4)
                {
                    lig--;
                    col--;
                    total++;
                }
                
                /*Vers le bas*/
                while ((g[lig][col]==pion) && lig<5 && col<NBCOL-1 && total!=4)
                {
                    lig++;
                    col++;
                    total++;
                }
            }

        }
        
    }
    
    return res;
}