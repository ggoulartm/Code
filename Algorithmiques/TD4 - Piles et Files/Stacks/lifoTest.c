// Code de test des piles, dans le cas où les éléments sont des double
#include "lifo.h"

int main() {
  lifo_t une_pile = lifo_new();

  une_pile = lifo_push(9.5, une_pile);
  printf("L'élément en tete de pile vaut : %.2lf\n", lifo_peek(une_pile));
  // affiche 9.5 . Remarque : l'élément n'a pas été enlevé

  une_pile = lifo_push(6.0, une_pile);
  une_pile = lifo_push(5.4, une_pile);
  une_pile = lifo_push(3.6, une_pile);

  affiche(une_pile);


  element_t ancienne_tete = lifo_pop( &une_pile );
  printf("L'élément qui vient d'être supprimé en tete de pile vaut : %lf\n", ancienne_tete);
  // affiche 3.6

  une_pile = lifo_delete(une_pile);

  return 0;
}