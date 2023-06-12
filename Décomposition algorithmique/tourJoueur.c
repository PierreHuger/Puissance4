#include <stdio.h>
#include <stdlib.h>
void tourJ(int *);

int main()
{
    int joueur;
    joueur=0;

    tourJ(&joueur);

    if (joueur==0)
    {
        printf("Joueur 1");
    }
    else if (joueur==1)
    {
        printf("Joueur 2");
    }

    return EXIT_SUCCESS;
}
void tourJ(int *i)
{
    int a;
        
    printf("Valeur:\n");
    scanf("%d", &a);

    while (a!=0)
    {
        printf("Tableau\n");
        if (i==0)
        {
            printf("C'est au Joueur 1 de jouer.\n");
            i=i+1;
        }
        else if (i==1)
        {
            printf("C'est au Joueur 2 de jouer.\n");
            i=i-1;
        }
        
        printf("Valeur:\n");
        scanf("%d", &a);
    }
}