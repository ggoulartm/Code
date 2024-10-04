/*
Université Grenoble Alpes - Grenoble INP / Phelma
Disciplina de Algorithmes - Filière SEOC
Author: Gabriel Goulart Müller
Data 04/10/2024

Travail Dirigé 4 - TD4
Generic Types - Piles et Files
*/

#include "pile.h"

//La méthode constructeur de pile doit retourner une pile
//dedans la méthode il faut instantier une pile et l'alloquer dans la memoire
lifo_t lifo_new(void (*fprint_data)(void*,FILE*),void* (*delete_data)(void*),
          int (*equal_data)(void*,void*)) 
          {
            printf("il faut implementer le Constructeur de Pile encore\n");
            return NULL;
          }


//la methode doit effacer de la mémoire tous les donnés qui étaient dedans la pile
//et effacer la pile de la mémoire aussi, après ça elle doit retourner un pointeur NULL
lifo_t delete_pile(lifo_t lifo){
    return NULL;
}

//la méthode suivante doit empiler l'element au-dessus de la pile
lifo_t push(lifo_t lifo, void* data){
    return NULL;
}

//Consulter la pile veut dire que il faut tester si la pile est vide
//si il y ait quelque chose la elle doit retourner l'élement au dessus de la pile
void consulter(lifo_t lifo){
    printf("il faut implementer la méthode Consulter Pile encore\n");
}

//Cette méthode a comme but de retirer l'élement qui est à la tête de la pile
//il faut juste changer le pointeur du deuxième élement et retourner le premier
void pop(lifo_t lifo){
    printf("il faut implementer encore\n");
}

//Si la pile est vide la méthode doit retourner VRAI (1), sinon FAUX (0)
int lifo_is_empty(lifo_t lifo){
    printf("il faut implementer la méthode Pile Vide encore\n");
    printf("Pile is empty, returning 1\n");
    return 1;
}

//Affiche le donné qui est à la tête de la pile et fait ça recursivement
void print_tete_recurs(pile_t t){
    printf("%s",(char*)t->data);
    if(t->next==NULL) return;
    print_tete_recurs(t->next);
}

//La but ici est de afficher tous les élements de la pile
void print_lifo(lifo_t lifo){
    if(lifo_is_empty(lifo)) return;
    print_tete_recurs(lifo->data);
}

//retourne la taille de la pile
int compter_lifo(lifo_t lifo){
    return lifo->size;
}