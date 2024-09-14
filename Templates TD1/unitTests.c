#include <time.h>
#include "generictab.h"

#define NBTESTS 100
#define NBCAS 4
// Programme de tests aleatoire


maketabletype(double)
maketablefunction(double)

void double_fprintf(double* v,FILE* fp) { fprintf(fp,"%.2lf ",*v); }
int double_equal(double* pv1, double *pv2) { return *pv1==*pv2; }
double* double_delete(double* db) {free(db); return db;}

int main() {
  srand( time(NULL) );
  table_double_t t1 = table_double_new(1000,double_fprintf,double_delete,double_equal);
  double x;
  int i,j,pos,nb;

  for (j=0; j<NBTESTS; j++) {
    switch(random() % NBCAS) {
      case 0: 
      case 1:
        x = random() % 100;
        printf("Append de %.2lf \n",x);
        t1=table_double_append(x,t1);
        break;
      case 2:
        x = random() % 100;
        pos=random()%(t1->actual_size+1);
        printf("Insertion de %.2lf en position %d\n",x,pos);
        t1=table_double_insert_at(x,pos,t1);
        break;
      case 3:
        if(t1->actual_size==0){break;}
        pos=random()%(t1->actual_size);
        printf("Suppression de l'element en position %d \n",pos);
        t1=table_double_remove_at(pos,t1);
        break;
    }
    table_double_printf(t1);
  }
  printf("Liberation du tableau\n");
  t1=table_double_delete(t1);
}