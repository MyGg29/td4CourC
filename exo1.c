
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
    newElement = malloc(sizeof(listeChaine));
    source->next = newElement;
    return source;
}

int main(int argc, char* argv[]){
    listeChaine *liste;
    liste = malloc(sizeof(listeChaine));
    liste->valeur = 10;
    printf("%d\n",liste->valeur);
    ajouterElement(liste);
    liste->next->valeur = 5;
    printf("%d", liste->next->valeur);
    return 0;
}
