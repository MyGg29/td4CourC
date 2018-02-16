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

int compterOccurences(listeChaine *source, int entier){
    int result = 0;
    for(listeChaine *i = source; i->next != NULL; i=i->next){
        if(i->valeur == entier){
            result++;
        }
    }
    return result;
}

void supprimerValeur(listeChaine *source, int entier, int boolen){
    listeChaine *firstElement = source;
    listeChaine *elementAvantElementASupprimer;
    while(source->valeur != entier && source != NULL){
        elementAvantElementASupprimer = source;
        source = source->next;
    }
    elementAvantElementASupprimer->next = source->next;
    free(source);
    source = firstElement;
}

void fussionnerListes(listeChaine *source, listeChaine *secSource){
    listeChaine *firstElement = source;
    for(; source->next != NULL; source = source->next){}
    source->next = secSource;    
    source = firstElement;
}

int compter(listeChaine *source){
    int compte = 0;
    for(listeChaine *i = source; i != NULL; i = i->next){
        compte++;
    }
    return compte;
}


int main(int argc, char* argv[]){
    listeChaine *liste;
    listeChaine *secListe;
    liste = malloc(sizeof(listeChaine));
    secListe = malloc(sizeof(listeChaine));

    liste->valeur = 10;
    ajouterElement(liste);
    liste->next->valeur = 5;
    ajouterElement(liste);
    liste->next->next->valeur = 7;
    
    secListe->valeur = 11;
    ajouterElement(secListe);
    secListe->next->valeur = 6;
    ajouterElement(secListe);
    secListe->next->next->valeur = 8;

    fussionnerListes(liste, secListe);
    //afficherElements(liste);

    int compte = compter(liste);
    printf("%d", compte);
    return 0;
}
