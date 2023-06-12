#include <stdio.h>
#include <stdlib.h>

const char TOMBE=' ';
const char GAUCHE='q';
const char DROITE='d';
const char VIDE='_';
const int DEBUT=4;
const char JETON='X';

int main()
{
    char tabDeplacement[7] = {VIDE};
    char deplacement;
    int i, j;
    
    tabDeplacement[4]=JETON;


    for (j=0; j<7; j++)
    {
        printf(" %c", tabDeplacement[j]);
    }
    
    printf("Déplacer votre jeton avec les touches q et d\n");
    scanf(" %c", &deplacement);
    
    i=DEBUT;
    
    do
    {
        if(deplacement!=TOMBE)
        {
            if(deplacement==DROITE)
            {
                tabDeplacement[i]=VIDE;

                i=i+1;
                tabDeplacement[i]=JETON;
                printf("Déplacement à droite, i=%d\n", i);
            }
            else if (deplacement==GAUCHE)
            {
                tabDeplacement[i]=VIDE;

                i=i-1;
                tabDeplacement[i]=JETON;
                printf("Déplacement à gauche, i=%d\n", i);
            }

            for (j=0; j<7; j++)
            {
                printf(" %c", tabDeplacement[j]);
            }
        }
        if ((i<7)&&(i>0))
        {
            printf("Déplacer votre jeton avec les touches q et d\n");
            scanf(" %c", &deplacement);
        }
    }while(((i<7)&&(i>0))&&(deplacement!=TOMBE));
    
    printf("Fin de programme, i=%d\n", i);

    return EXIT_SUCCESS;
}
