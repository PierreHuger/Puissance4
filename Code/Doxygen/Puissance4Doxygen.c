/**
 * \brief Programme du Puissance4
 * 
 * \author HUGER Pierre
 * 
 * \version Finale
 * 
 * \date 22 Novembre 2022
 * 
 * Ce Programme permet de jouer au Puissance 4.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


/**
 * \def PION_A
 * 
 * \brief Constante pour le jeton du joueur 1
*/
const char PION_A='X'; //joueur 1

/**
 * \def PION_b
 * 
 * \brief Constante pour le jeton du joueur 2
*/
const char PION_B='O'; //joueur 2

/**
 * \def VIDE
 * 
 * \brief constante pour les cases vides de la Grille
*/
const char VIDE='_';

/**
 * \def INCONNU
 * 
 * \brief Constante de vide pour indiquer la fin du choix de la colonne
*/
const char INCONNU= ' ';

/**
 * \def NBLIG
 * 
 * \brief Constante qui représente le nombre de lignes de la Grille
*/
const int NBLIG= 6; //Nombre de lignes

/**
 * \def NBCOL
 * 
 * \brief Constante qui représente le nombre de colonnes de la Grille 
*/
const int NBCOL= 7; //Nombre de colonnes

/**
 * \def COLONNE_DEBUT
 * 
 * \brief Constante qui indique la colonne de debut pour le jeton à faire tomber
*/
const int COLONNE_DEBUT= 3;  //colonne de debut pour commencer au milieu du tableau pour choisirColonne

/**
 * \def LIG_DEBUT
 * 
 * \brief Constante qui permet de se placer sur la dernière ligne de la Grille
*/
const int LIG_DEBUT=5; //Ligne de debut, Permet de commencer en bas du tableau

bool Debut=true; //Permet d'afficher les règles au tout debut, sans ca les regles sont clear par la fonction afficher 

/**
 * \def NBLIG
 * 
 * \brief Définie le nombre de lignes de la Grille
*/
#define NBLIG 6

/**
 * \def NBCOL
 * 
 * \brief Définie le nombre de colonnes de la Grille
*/
#define NBCOL 7

/**
 * \typedef Grille
 * 
 * \brief Tableau du Puissance 4 définie par NBLIG et NBCOL
 * 
 * La Grille permet de stocker les jetons pour le Puissance 4
*/
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

/**
 * \fn initGrille(Grille g)
 * 
 * \brief Procédure qui initialise le tableau du Puissance 4 avec des caractères '_'
 * 
 * \param g : le Tableau à initialiser
*/
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

/**
 * \fn afficher(Grille g, char pion, int colonne)
 * 
 * \brief Procédure qui affiche la grille avec le jeton a jouer au dessus de celle-ci
 * 
 * \param g : Grille du puissance 4
 * \param pion : Le pion permet d'affiche le pion du joueur qui doit jouer 
 * \param colonne : Colonne indique la colonne au dessus de laquelle le pion doit se placer 
*/
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

/**
 * \fn bool grillePleine(Grille g)
 * 
 * \brief Fonction qui vérifie si le tableau est plein 
 * 
 * \param g: Grille du Puissance 4
 * 
 * \return true si le tableau est plein, false sinon
 * 
 * Cette fonction vérifie si le tableau est plein et donc si la partie est terminée ou pas 
*/
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

/**
 * \fn jouer(Grille g, char pion, int* ligne, int* colonne)
 * 
 * \brief Procédure qui appelle les fonctions choisirColonne et trouverLigne.
 * 
 * \param g: Tableau du Puissance 4
 * \param pion : Pion du joueur qui doit jouer
 * \param ligne : renvoie une ligne vide sur la colonne choisie
 * \param colonne : colonne choisie lors de la procédure choisirColonne
 * 
 * Cette procédure permet de jouer, de trouver une case vide dans la colonne choisie. Pour cela, elle appelle la fonction choisirColonne et la fonction trouverLigne
*/
void jouer(Grille g, char pion, int* ligne, int* colonne)
{
    do
    {
        *colonne = choisirColonne(g, pion, COLONNE_DEBUT); //Selectionne la colonne

        *ligne = trouverLigne(g, *colonne); //Selectionne la ligne
    }while(*ligne == -1);
    
    g[*ligne][*colonne]= pion;
}

/**
 * \fn int choisirColonne(Grille g, char pion, int colonne)
 * 
 * \brief Fonction qui permet de choisir la colonne dans laquelle on veut jouer le pion
 * 
 * \param t : Tableau du Puissance 4
 * \param pion : Pion du joueur qui doit jouer
 * \param colonne : Colonne de debut dans laquelle se place le pion avant d'être déplacé
 * 
 * \return Cette fonction retourne le numéro de la colonne choisie
 * 
 * Cette fonction permet de choisir la colonne dans laquelle on veut faire tomber le pion. On se déplace avec les touches q et d pour gauche et droite, ensuite avec 
 * espace on fait tomber le pion
*/
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

/**
 * \fn int trouverLigne(Grille g, int colonne)
 * 
 * \brief Fonction qui chercher une case vide dans la colonne choisie précédemment
 * 
 * \param g : Tableau du Puissance 4
 * \param colonne : Numéro de la colonne choisie dans choisirColonne
 * 
 * \return Le numéro de la ligne ou une case est vide
 *  
*/
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

/**
 * \fn estVainqueur(Grille g, int ligne, int colonne)
 * 
 * \brief Fonction qui vérifie si il y a un vainqueur docn si 4 jetons sont alignés
 * 
 * \param g : Tableau du Puissance 4
 * \param ligne : Numéro de ligne sur laquelle le joueur vient de jouer
 * \param ligne : Numéro de Colonne dans laquelle le joueur vient de jouer
 * 
 * \return true si il y a un vainqueur, false sinon
 * 
 * Cette fonction vérifie si il y a un vainqueur. La vérification se fait en ligne, en colonne, sur la diagonale gauche et sur la diagonale droite
*/
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

/**
 * \fn finDePartie(char pion)
 * 
 * \brief Procédure qui affiche une phrase de fin si le programme détecte que la partie était finie
 * 
 * \param pion : Pion du joueur qui a gagné s'il n'y a pas égalité
 * 
 * Cette procédure affiche une phrase pour annoncer le vainqueur, Joueur 1/Joueur 2 et aussi une phrase si la partie finie en égalité
*/
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