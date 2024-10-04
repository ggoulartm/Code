#include "./list/list.h"  // On importe le TAD liste chaînée dynamique
#include "element.h"

// 1. declaration du type lifo_t.
//    Il suffit de déclarer que "une pile est une liste" !
typedef list_t lifo_t ;

// Crée et retourne un pile vide ou NULL en cas d'erreur
lifo_t lifo_new() {
  return list_new(NULL,NULL,NULL); // "créer une pile, c'est en fait créer une liste !"
}


// Ajoute l'élément e à la pile s et retourne la nouvelle pile
lifo_t lifo_push(element_t e, lifo_t stack) {
  return list_add_first(e, stack); // "empiler, c'est en fait ajouter en tête de la liste !"
}


// Retourne l'élément en tête de pile (sans l'enlever de la pile)
// PRECONDITION : la pile  stack  ne doit pas être vide
element_t lifo_peek(lifo_t stack) {
  return list_first(stack);
}

// Enlève l'élément en tête de la pile, et retourne cet élément
// PRECONDITION : la pile pointée par  p_stack  ne doit pas être vide
element_t lifo_pop(lifo_t * p_stack) {
  element_t e = list_first(*p_stack);
  * p_stack   = list_del_first(*p_stack);
  return e;
}
