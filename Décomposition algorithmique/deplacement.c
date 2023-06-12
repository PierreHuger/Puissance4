#include <stdio.h>
#include <stdlib.h>

const char DROITE= 'd';
const char GAUCHE= 'q';
const char TOMBE= 's';
void dep();

int main()
{
    dep();
}
void dep(char deplacement[3];
)
{
    do
    {
        printf("Entrez un caractère (q/d/s):\n");
        scanf(" %s", deplacement);
    }while ((deplacement !=DROITE) || (deplacement!=GAUCHE));

    while (deplacement != 's')
    {
        if (deplacement==DROITE)
        {
            printf("Droite\n");
        }
        else if (deplacement==GAUCHE)
        {
            printf("Gauche\n");
        }
    }

    else if (deplacement==TOMBE)
    {
        printf("Tombe\n");
    }
}