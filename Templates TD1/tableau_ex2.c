#include <stdio.h>
#include <stdlib.h>

typedef struct  {
    double* data  ;         // Les données du tableau : un pointeur vers des pointeurs
    size_t size;      // La taille maximale

    void* (*delete_data)(double); // Un pointeur vers la fonction qui libère les éléments
    int (*equal_data)(void*,void*); // Comment tester l'egalite de 2 elements
    void (*fprint_data)(void*, FILE*); // Comment afficher un éléments
} * table_t;

  // Fonction allocation de la table
table_t table_new(int n) {
  table_t ptab;

    // Allocation de la structure
  ptab=calloc(1,sizeof(*ptab));
  ptab->size=n;
    // Allocation des données
    if ((ptab->data=calloc(n,sizeof(*(ptab->data))))==NULL) {
      free(ptab);
      return NULL;
    }
  return ptab;
}

table_t table_delete(table_t tab) { int i;
  if (tab==NULL) return NULL;
    // A t on passe une fonction de liberation des elements ?
  if (tab->delete_data)
      // On libere les elements grace à notre pointeur
    for (i=0; i<tab->size; i++)
      tab->delete_data(tab->data[i]);

    // On libere le tableau et la structure allouée
  free(tab->data);
  free(tab);
  return NULL;
}

int main() { int i;
  table_t ptab;

    // Creation du tableau
  printf("Taille du tableau ? \n"); scanf ("%d",&i);
  ptab= table_new(i);
    // Lecture clavier
  for ( i=0; i<ptab->size; i++)
    scanf("%lf", ptab->data+i);

    // Ajout aléatoire
  for ( i=0; i<ptab->size; i++)
    ptab->data[i] += random();

  // Libération du tableau
  free(ptab->data);
  free(ptab);
}