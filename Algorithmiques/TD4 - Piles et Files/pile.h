/*
Université Grenoble Alpes - Grenoble INP / Phelma
Disciplina de Algorithmes - Filière SEOC
Author: Gabriel Goulart Müller
Data 04/10/2024

Travail Dirigé 4 - TD4
Generic Types - Piles et Files
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _pile {
  void* data;               /* un élément de la liste*/
  struct _pile *next;       /* l'adresse du maillon suivant */
} *pile_t;

typedef struct _lifo{
  pile_t data;
  unsigned int size;

  void* (*delete_data)(void*);
  void (*fprint_data)(void*,FILE *);
  int (*equal_data)(void*,void*);
} * lifo_t;

//Créer (new) : créer une pile vide
lifo_t lifo_new(void (*fprint_data)(void*,FILE*),void* (*delete_data)(void*),
          int (*equal_data)(void*,void*)) ;

//Détruire (delete) : détruire une pile
lifo_t delete_pile(lifo_t lifo);

//Empiler (push) : ajouter un élément sur la pile
lifo_t push(lifo_t lifo, void* data);

//Consulter la tête (peek) : récupérer le dernier élément ajouté (on dit la "tête de pile") sans l'enlever. N'a pas de sens si la pile est vide.
void consulter(lifo_t lifo);

//Dépiler (pop) : récupérer la tête et l'enlever de la pile. N'a pas de sens si la pile est vide.
void pop(lifo_t lifo);

//Tester si vide : retourner VRAI ou FAUX suivant que la pile est vide ou non
int pile_is_empty(lifo_t lifo);

//Afficher : affiche tous les éléments présents dans la pile
void print_pile(lifo_t lifo);

//Compter : retourne le nombre d'éléments présents dans la pile
int compter_pile(lifo_t lifo);