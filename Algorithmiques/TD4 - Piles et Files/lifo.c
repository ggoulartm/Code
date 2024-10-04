#include "./list/list.h"  // On importe le TAD liste chaînée dynamique
#include "element.h"

// 1. declaration du type lifo_t.
//    Il suffit de déclarer que "une pile est une liste" !
typedef list_t lifo_t ;

element_t* delete_data(element_t* e){
    free(e);
    return e;
}

void fprintf_data(double* v,FILE* fp){
    fprintf(fp,"%lf ",*v);
}

// Crée et retourne un pile vide ou NULL en cas d'erreur
lifo_t lifo_new() {
  return list_new(&fprintf_data,delete_data,NULL); // "créer une pile, c'est en fait créer une liste !"
}

//list push transforms linked lists in stack type
list_t list_push(void* e, list_t l){
    if(l->size>0){
        return list_add_last(e,l);
    }
    return list_add_first(e,l);
}


// Ajoute l'élément e à la pile s et retourne la nouvelle pile
lifo_t lifo_push(element_t e, lifo_t stack) {
    element_t *px;
    px=malloc(sizeof(element_t));
    *px=e;
  return list_push(px, stack); // "empiler, c'est en fait ajouter en tête de la liste !"
}


// Retourne l'élément en tête de pile (sans l'enlever de la pile)
// PRECONDITION : la pile  stack  ne doit pas être vide
element_t lifo_peek(lifo_t stack) {
    element_t *px;
    px=malloc(sizeof(element_t));
    px=(double *)list_first(stack);
  return *px;
}

// Enlève l'élément en tête de la pile, et retourne cet élément
// PRECONDITION : la pile pointée par  p_stack  ne doit pas être vide
element_t lifo_pop(lifo_t * p_stack) {
  element_t e = *(double *)list_last(*p_stack);
  * p_stack   = list_del_last(*p_stack);
  return e;
}

lifo_t lifo_delete(lifo_t stack) {
    return list_delete(stack);
}

void affiche(lifo_t stack){
    list_printf(stack);
}