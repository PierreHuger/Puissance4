#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char DROITE= 'd';
const char GAUCHE= 'q';
const char TOMBE= 's';

void deplacement();

int main()
{
    deplacement();
}

void deplacement()
{
    char dep;
    printf("Entrez un caractère:\n");
    scanf("%c", &dep);

    if (dep== DROITE)
    {
        printf("droite\n");
    }
}
