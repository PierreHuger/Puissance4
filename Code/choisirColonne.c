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
typedef char tab[NBCOL];

int choisirColonne(Grille, tab, char, int);
void initGrille(Grille);
void afficher(Grille, tab, char, int);

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

int choisirColonne(Grille t, tab g, char pion, int colonne)
{
    char deplacement, poubelle;;
    int i, j;

    for(j=0;j<NBCOL;j++)
    {
        g[j]=INCONNU;
    }

    i=colonne;
    g[i]=pion;

    for(j=0;j<NBCOL;j++)
    {
        printf(" %c", g[j]);
    }

    printf("\n");

    printf("Deplacement a gauche ou a droite ? (q/d)\n");
    scanf("%c", &deplacement);
    scanf("%c", &poubelle);

    do
    {

        if((i<=NBCOL)&&(i>=0))
        {
            if((deplacement=='q')&&(i>0))
            {
                i=i-1;
                g[i]=pion;
                g[i+1]=INCONNU;
            }
            else if((deplacement=='d')&&(i<NBCOL-1))
            {
                i=i+1;
                g[i]=pion;
                g[i-1]=INCONNU;
            }
        }
        
        
        for(j=0;j<NBCOL;j++)
        {
            printf(" %c", g[j]);
        }
        
        printf("\n");

        printf("Deplacement a gauche ou a droite ? (q/d)\n");
        scanf("%c", &deplacement);
        scanf("%c", &poubelle);


    }while(deplacement!=' ');

    return i;
}