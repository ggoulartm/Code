#include <time.h>
#include "genericPointer.c"

#define NBTESTS 100
#define NBCAS 4
// Programme de tests aleatoire


int main() {
  srand( time(NULL) );
  table_t t1 = table_new(1000,NULL,NULL,NULL);
  double *x;
  int i,j,pos,nb;
    x= malloc(sizeof(*x));
  for (j=0; j<NBTESTS; j++) {
    switch(random() % NBCAS) {
      case 0: 
      case 1:
        *x = random() % 100;
        printf("Append de %.2lf \n",*x);
        t1=table_append(x,t1);
        break;
      case 2:
        if(t1->actual_size==0){break;}
        *x = random() % 100;
        pos=random()%(t1->actual_size);
        printf("Insertion de %.2lf en position %d\n",*x,pos);
        t1=table_insertat(pos,x,t1);
        break;
      case 3:
        if(t1->actual_size==0){break;}
        pos=random()%(t1->actual_size);
        printf("Suppression de l'element en position %d \n",pos);
        t1=table_removeat(t1,pos);
        break;
    }
    table_print(t1);
  }
  printf("Liberation du tableau\n");
  table_delete(t1);
}