
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct listeChaine_{
    int valeur;
    int secValeur;
    struct listeChaine_ *next;
}listeChaine;

listeChaine* ajouterElement(listeChaine *source){
    listeChaine * newElement;
    listeChaine *i;
    newElement = malloc(sizeof(listeChaine));
    for(i=source; i->next!=NULL; i = i->next){}
    i->next = newElement;
    return source;
}

void afficherElements(listeChaine *source){
    listeChaine *firstElement = source;
    do{
        printf("%d\n", source->valeur);
        source = source->next;
    }while(source != NULL); 
    source = firstElement;
}

int main(int argc, char* argv[]){
    listeChaine *liste;
    liste = malloc(sizeof(listeChaine));
    liste->valeur = 10;
    ajouterElement(liste);
    liste->next->valeur = 5;
    afficherElements(liste);
    ajouterElement(liste);
    liste->next->next->valeur = 7;
    afficherElements(liste);
    return 0;
}
