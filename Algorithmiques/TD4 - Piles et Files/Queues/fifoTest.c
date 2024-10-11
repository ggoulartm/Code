#include <stdio.h>
#include "fifo.h"

int main() {
    // file de double
    // Ajout en tete avec la fonction de base
  fifo_t l1=fifo_new();
  element_t pv;
  printf("Ajout de 10,20,30,40,50,60,70 : \n");
  l1=fifo_enqueue(10,l1);
    fifo_print(l1);
  l1=fifo_enqueue(20,l1);
    fifo_print(l1);
  pv=30; l1=fifo_enqueue(pv,l1);
  pv=40; l1=fifo_enqueue(pv,l1);
    fifo_print(l1);
  l1=fifo_enqueue(50,l1);
    fifo_print(l1);
  l1=fifo_enqueue(60,l1);
    fifo_print(l1);
  l1=fifo_enqueue(70,l1);
    fifo_print(l1);
  printf("Affichage par queue_type_printf :\n");
  fifo_print(l1);

  pv =fifo_dequeue(l1);
  printf("Defiler :%lf\n",pv);

  fifo_print(l1);

  pv =fifo_dequeue(l1);
  printf("Defiler :%lf\n",pv);

  fifo_print(l1);

  printf("Liberation de la queuee\n");
  l1=fifo_delete(l1);

  return EXIT_SUCCESS;
}