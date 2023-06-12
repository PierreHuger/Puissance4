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
    char vainqueur;
    int ligne, colonne;
    Grille Puissance4;

    /* Regles/consignes */
    printf("Pour gagner vous devez aligner 4 jetons\n");
    printf("\n");
    printf("Joueur 1: X\nJoueur 2: O\n");
    printf("\n");
    printf("Pour vous deplacer:\n q: Gauche\n d: Droite\n Mettre un espace pour faire tomber le jeton\n");
    printf("\n");
    printf("Bonne partie !!");
    printf("\n");
    printf("\n");


    initGrille(Puissance4);
    vainqueur=INCONNU;
    
    while ((vainqueur==INCONNU) && !grillePleine(Puissance4))
    {
        jouer(Puissance4, PION_A, &ligne, &colonne);
        afficher(Puissance4, PION_B, COLONNE_DEBUT);

        if(estVainqueur(Puissance4, ligne, colonne))
        {
            vainqueur=PION_A;
        }
        else if (!grillePleine(Puissance4))
        {
            jouer(Puissance4, PION_B, &ligne, &colonne);
            afficher(Puissance4, PION_A, COLONNE_DEBUT);
            if (estVainqueur(Puissance4, ligne, colonne))
            {
                vainqueur=PION_B;
            }
        }
    }
    finDePartie(vainqueur);
}

void initGrille(Grille g)
{
    int i, j;

    /*Initialise la grille avec des caractères '_'*/
    for(i=0;i<NBLIG;i++)
    {
        for(j=0;j<NBCOL;j++)
        {
            g[i][j]=VIDE;
        }
    }
}

void afficher(Grille g, char pion, int colonne)
{
    int i, j;

    if(!Debut)
    {
        system("clear");
    }
    
    /*Affiche le pion a deplacer au dessus de la Grille*/
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
    
    /*Affiche la Grille du Puissance4*/
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

    return res;
}

void jouer(Grille g, char pion, int* ligne, int* colonne)
{
    do
    {
        *colonne = choisirColonne(g, pion, COLONNE_DEBUT); //Selectionne la colonne

        *ligne = trouverLigne(g, *colonne); //Selectionne la ligne
    }while(*ligne == -1);
    
    g[*ligne][*colonne]= pion;
}

/*Cette fonction permet de choisir la colonne dans laquelle on veut faire tomber le pion*/
int choisirColonne(Grille t, char pion, int colonne)
{
    char deplacement, poubelle;
    int indice_col;
    
    indice_col=colonne;
    
    afficher(t, pion, indice_col);
    Debut=false;

    printf("Deplacement a gauche ou a droite ? (q/d)\n");
    scanf("%c%c", &deplacement, &poubelle); //poubelle permet d'éviter le retour chariot     
    
    do
    {

        if((indice_col<=NBCOL)&&(indice_col>=0))
        {
            if((deplacement=='q')&&(indice_col>0))
            {
                indice_col=indice_col-1; //si 'q' alors l'indice se déplace d'une case vers la gauche
            }
            else if((deplacement=='d')&&(indice_col<NBCOL-1))
            {
                indice_col=indice_col+1; //si 'd' alors l'indice se déplace d'une case vers la droite
            }
        }

        if(deplacement!=INCONNU)
        {
            afficher(t, pion, indice_col);

            printf("Deplacement a gauche ou a droite ? (q/d)\n");
            scanf("%c%c", &deplacement, &poubelle);        
        }
                
    }while(deplacement!=INCONNU); //condition de fin de boucle, ici un espace --> INCONNU==' '

    return indice_col; //Cette fontion retourne l'indice de la colonne dans laquelle faire tomber le jeton
}

/*Cette fonction permet de trouver une case vide dans la colonne choisit auparavant dans choisirColonne*/
int trouverLigne(Grille g, int colonne)
{
    int i, resultat;
    i=LIG_DEBUT;
    resultat=-1;

    while((resultat==-1)&&(i>=0))
    {
        if(g[i][colonne]==VIDE)
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

/*Cette fonction vérifie dans la Grille s'il y a un Vainqueur*/
bool estVainqueur(Grille g, int ligne, int colonne)
{
    int total, j, i;
    char pion;
    bool res;

    res=false;
    total=1;
    pion=g[ligne][colonne];
    j=1;
    i=1;

    /*Cette boucle permet de vérifier si 4 jetons sont alignés sur une ligne*/
    
    /*Vers la gauche*/
    while (g[ligne][colonne-j]==pion && colonne-j>=0)
    {
        total++;
        j++;
    }

    j=1;

    /*Vers la droite*/
    while (g[ligne][colonne+j]==pion && colonne+j<NBCOL)
    {
        total++;
        j++;
    }

    //attribue vrai au resultat si 4 jetons sont alignés 
    if(total>=4)
    {
        res=true;
    }

    total=1;
    
    if(!res) //permet d'éviter de faire les vérifications si le res est vrai car cela veut dire qu'il y a un vainqueur
    {
        /*Cette boucle permet de vérifier si 4 jetons sont alignés en colonne*/

        /*Vers le bas*/
        while (g[ligne+i][colonne]==pion && ligne+i<NBLIG)
        {
            total++;
            i++;
        }

        /*attribue vrai au resultat si 4 jetons sont alignés*/ 
        if(total==4)
        {
            res=true;
        }

        j=1;
        i=1;
        total=1;

        if(!res)
        {
            /*Cette boucle permet de vérifier si 4 jetons sont alignés sur la diagonale gauche*/
            /*Vers le haut*/
            while ((g[ligne-i][colonne-j]==pion) && ligne-i>=0 && colonne-j>=0)
            {
                i++;
                j++;
                total++;
            }
            
            j=1;
            i=1;
            
            /*Vers le bas*/
            while (g[ligne+i][colonne+j]==pion && ligne+i<NBLIG && colonne+j<NBCOL)
            {
                i++;
                j++;
                total++;
            }

            /*attribue vrai au resultat si 4 jetons sont alignés*/ 
            if(total==4)
            {
                res=true;
            }

            j=1;
            i=1;
            total=1;

            if(!res)
            {
                /*Cette boucle permet de vérifier si 4 jetons sont alignés sur la diagonale droite*/
                
                /*Vers le haut*/
                while ((g[ligne-i][colonne+j]==pion) && ligne-i>=0 && colonne+j<NBCOL)
                {
                    i++;
                    j++;
                    total++;
                }
                
                j=1;
                i=1;
                
                /*Vers le bas*/
                while ((g[ligne+i][colonne-j]==pion) && ligne-i<NBLIG && colonne-j>=0)
                {
                    i++;
                    j++;
                    total++;
                }

                if(total==4)
                {
                    res=true;
                }
            }
        }   
    }
    
    return res; //Cette fonction retourne un booléen qui permet de savoir si il y a un gagnant
}

/*Cette procédure affiche le vainqueur*/
void finDePartie(char pion)
{
    if(pion==PION_A)
    {
        printf("Le vainqueur de la partie est le joueur 1\n");
    }
    else if(pion==PION_B)
    {
        printf("Le vainqueur de la partie est le joueur 2\n");
    }
    else//egalité
    {
        printf("Egalité\n");
    }
}