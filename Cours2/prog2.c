/**
* \brief Programme de manipulation de chaînes de carctères.
* \author HUGER Pierre 
* \version 1.0
* \date 25 octobre 2022
* Le programme principal traite un exemple qui teste quelques fonctions :
* il crée deux chaines, les affiche, puis ordonne la deuxième et l'affiche.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/**
 * \def TMAX
 * \brief Taille Maximum d'une chaine quand on veut ordonner ses caractères
*/
#define TMAX 20	

/**
 * \struct liste de chaine
 * \brief structure d'un élément de la liste chaine. Un caractère+un pointeur sur caractère suivant 
*/
typedef struct Elem {		
    char lettre;			
    struct Elem * svt;	 
}element;				

/**
 * \typedef chaine
 * \brief une chaine est un pointeur sur un élément
*/
typedef element * chaine;	

/**
 * \typedef typTab
 * \brief type tableau de TMAX caractère qui ordonne les caractères d'une chaine 
*/
typedef char typTab[TMAX]; 	


/**********************************************************/
/* prototype des fonctions disponibles dans ce programme */
/**********************************************************/

/**
 * \fn Initialisation d'une chaine
*/
void init(chaine * ch);

/**
 * \fn teste si la chaine est vide 
*/
bool estV(chaine ch);	

/**
 * \fn ajoute un caractère en début de chaine
*/
void ajT(chaine * ch, char c);

/**
 * ajoute un caractère en fin de chaine
*/
void ajQ(chaine * ch, char c);

// compte le nombre de caract�res d'une chaine

int nbC(chaine ch);

// affiche la chaine � l'�cran
void aff(chaine ch);

// concat�ne deux chaines en une troisi�me
void cat(chaine ch1, chaine ch2, chaine * ch3);

// indique si in caract�re est pr�sent dans une chaine
bool app(chaine ch, char c);

// indique si deux chaines sont identiques
bool ide(chaine ch1, chaine ch2);

// indique si une chaine est l'inverse d'une autre
void inv(chaine ch1, chaine * ch2);

// indique si une chaine est un palindrome
bool pal(chaine ch1);

// indique si deux chaines sont anagrammes
bool ana(chaine ch1, chaine ch2);

// ordonne de mani�re croissante les caract�res d'une chaine
void ord(chaine * ch);

/************************************************************/
/* Le programme principal traite un exemple pour tester	*/
/* quelques fonctions	: il cr�e deux chaines, les affiche,	*/
/* puis ordonne la deuxi�me et l'affiche				*/
/************************************************************/
int main()
{
    chaine ch1, ch2;
    init(&ch1);
    init(&ch2);

    ajQ(&ch1, 'C');
    ajQ(&ch1, 'H');
    ajQ(&ch1, 'I');
    ajQ(&ch1, 'E');
    ajQ(&ch1, 'N');
    aff(ch1);

    ajQ(&ch2, 'N');
    ajQ(&ch2, 'I');
    ajQ(&ch2, 'C');
    ajQ(&ch2, 'H');
    ajQ(&ch2, 'E');
    aff(ch2);
    ord(&ch2);
    aff(ch2);

    return EXIT_SUCCESS;
}

void init(chaine * ch){
    *ch=NULL;
}

bool estV(chaine ch){
    return ch==NULL;
}

void ajT(chaine * ch, char c){
    element * nouveau = (element*)malloc(sizeof(element));
    nouveau->lettre = c;
    nouveau->svt = *ch;
    *ch = nouveau;
}

void ajQ(chaine * ch, char c){
    element * ptCourant;
    element * nouveau = (element*)malloc(sizeof(element));
    nouveau->lettre = c;
    nouveau->svt = NULL;

    if (estV(*ch)){
        *ch = nouveau;
    } else {
        ptCourant = *ch;
        while (ptCourant->svt != NULL){
            ptCourant = ptCourant->svt;
        }
        ptCourant->svt = nouveau;
    }
}

int nbC(chaine ch){
    int nb = 0;
    element * ptCourant = ch;
    while (ptCourant != NULL){
        ptCourant = ptCourant->svt;
        nb++;
    }
    return nb;
}

void aff(chaine ch){
    if (!estV(ch)){
        printf("%c", ch->lettre);
        aff(ch->svt);
    } else {
        printf("\n");
    }
}

bool ide(chaine ch1, chaine ch2){
    element * ptCourant1 = ch1;
    element * ptCourant2 = ch2;
    bool pareil = true;
	// cette fonction parcourt parall�lement les deux
 	// chaines, caract�re par caract�re, tant que les 
	// caract�res correspondants sont les m�mes
    while (pareil && ptCourant1!=NULL){
        if (ptCourant2==NULL){
            pareil = false;
        } else if (ptCourant1->lettre != ptCourant2->lettre){
            pareil= false;
        } else {
            ptCourant1 = ptCourant1->svt;
            ptCourant2 = ptCourant2->svt;
        }
    }
    return pareil && ptCourant2==NULL;

}

void inv(chaine ch1, chaine * ch2){
    element * ptCourant;

    ptCourant = ch1;
    while (ptCourant != NULL){
        ajT(ch2, ptCourant->lettre);
        ptCourant = ptCourant->svt;
    }
}

bool pal(chaine ch1){
    chaine ch;

    init(&ch);
    inv(ch1, &ch);
    return ide(ch1, ch);
}

bool app(chaine ch, char c){
// recherche s�quentielle classique
    bool trouve = false;
    element * ptCourant = ch;

    while (!trouve && ptCourant!=NULL){
        if (ptCourant->lettre==c){
            trouve = true;
        } else {
            ptCourant = ptCourant->svt;
        }
    }
    return trouve;
}

bool supprimer(chaine * ch, char c){
    bool trouve = false;
    element * ptCourant = *ch;
    element * ptPrec = NULL;

    while (!trouve && ptCourant!=NULL){
        if (ptCourant->lettre==c){
            trouve = true;
        } else {
            ptPrec = ptCourant;
            ptCourant = ptCourant->svt;
        }
    }
    if (trouve){
        if (ptPrec==NULL) {
            *ch = ptCourant->svt;
        } else {
            ptPrec->svt = ptCourant->svt;
        }
        free(ptCourant);
        ptCourant = NULL;
    }
    return trouve;
}


/************************************************************
* Attention, dans cette fonction la chaine ch2 est modifi�e !
*************************************************************/
bool ana(chaine ch1, chaine ch2){
    bool anag = true;	//ch1 et ch2 sont anagrammes tant qu'on
						// n'a pas prouv� le contraire
    
	element * ptCourant = ch1;

    	// On parcourt toute la liste ch1. A chaque element, on
    	// enl�ve dans ch2 le caractere courant correspondant 
		// de ch1
    	// Si on trouve pas c'est fini et le r�sultat est faux 
    	// Mais si a la fin, ch2 est vide alors c'est OK

    while (anag && ptCourant!=NULL){
        if (! supprimer(&ch2, ptCourant->lettre)){
            anag = false;
        }
        ptCourant = ptCourant->svt;
    }
	// retourne VRAI si on a d�tect� un anagramme ET que ch2
	// a �t� enti�rement vid�e
    return anag && estV(ch2);	
}


// fonction utilis�e par la fonction ord
// elle copie les caract�res d'une Liste
// vers un Tableau A CONDITION QUE LA CHAINE FASSE
// MOINS DE AX CARACTERES
//
int LvT(chaine ch, typTab t){
    int i=0;
    int N = nbC(ch);

    if (N<=TMAX){
        chaine pt = ch;
        while (pt!=NULL){
            t[i] = pt->lettre;
            i++;
            pt = pt->svt;
        }
    } else {
        N = -1;
    }
    return N;
}


// fonction utilis�e par la fonction ord
// elle copie les caract�res d'un Tableau vers une Liste
//
void TvL(typTab t, chaine * ch, int N){
    int i;

    for (i=0 ; i<N ; i++){
        ajQ(ch, t[i]);
    }
}


// fonction utilis�e par la fonction ord
// elle trie le tableau de caract�res par ordre croissant

void trT(typTab t, int N){
    int i, j;
    bool inf;
    char tmp;

    for(i=1;i<N;i++){
        j=i;
        inf=true;
        while (j>0 && inf){
            if(t[j] < t[j-1]){
                tmp = t[j];
                t[j] = t[j-1];
                t[j-1] = tmp;
                j--;
            }else{
                inf = false;
            }
        }
    }
}


// fonction qui ordonne les caract�res d'une Liste (ordre
// croissant) en utilisant un tableau interm�diaire
// CONDITION la chaine doit faire moins de TMAX c'est � dire
// le r�sultat retourn� par LvT doit �tre diff�rent de -1
//
void ord(chaine * ch){
    typTab t;
    int N = LvT(*ch, t);
    if (N!=-1){
        trT(t, N);
        *ch = NULL;
        TvL(t, ch, N);
    }
}
