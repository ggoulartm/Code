#include "generictab.h"

maketabletype(double)
maketablefunction(double)

void double_fprintf(double* v,FILE* fp) { fprintf(fp,"%lf ",*v); }
int double_equal(double* pv1, double *pv2) { return *pv1==*pv2; }

int main() { int i;
  table_double_t t1;
    // tableau de 10 reels
    // comme ce sont des reels, pas de liberation des elements
    // donc le 2ieme parametre est NULL
    // double_fprint et double_equal sont ailleurs....
  t1=table_double_new(10,double_fprintf,NULL,double_equal);
  if (t1==NULL) {
    printf("Erreru allocation\n");
    exit(EXIT_FAILURE);
  }
    // On remplit avec des valeurs aléatoires
  for (i=0; i<t1->max_size-1; i++) {
    t1->data[i]=random() %100;
    t1->actual_size++;
  }
    // On affiche
  for (i=0; i<t1->actual_size; i++)
    printf("%.2lf ",t1->data[i]);
    // Mais il faut liberer ....
    // sans liberer les elements qui sont des double
    // et non des pointeurs vers des doubles
    // donc, delete_data est NULL
    printf("\n");
    table_double_append(50.13,t1);
    table_double_remove_at(0,t1);
    table_double_insert_at(3.14,2,t1);
    table_double_printf(t1);
    printf("\n");
  table_double_delete(t1);
}