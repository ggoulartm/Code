// fichier lifo.h pour l'implantation du TAD pile au moyen d'une liste chaînée dynamique
#ifndef LIFO_H_
#define LIFO_H_

#include "lifo.c"


// 2. prototype des fonctions de l'API du TAD Pile

// Crée et retourne un pile vide ou NULL en cas d'erreur
lifo_t lifo_new();

// Détruit la pile et retourne une pile vide
lifo_t lifo_delete(lifo_t stack);

// Retourne 1 si la pile  stack   est vide, 0 sinon
int lifo_is_empty(lifo_t stack);

// Ajoute l'élément e à la pile  stack  et retourne la nouvelle pile
lifo_t lifo_push(element_t e, lifo_t stack);

// Retourne l'élément en tête de pile (sans l'enlever de la pile)
// PRECONDITION : la pile  stack  ne doit pas être vide
element_t lifo_peek(lifo_t stack);

// Enlève l'élément en tête de la pile, et retourne cet élément
// PRECONDITION : la pile pointée par  p_stack  ne doit pas être vide
element_t lifo_pop(lifo_t * p_stack);

#endif