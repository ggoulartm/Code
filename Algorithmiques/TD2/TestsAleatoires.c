#include "genericVector.c"

#define NBTESTS 10000
#define NBCAS 4
// Programme de tests aleatoire
// 3 fois plus d'ajout que de suppression
int main() {
  vect_t t1 = vect_new(2);
  double x;
  int i,j,nb;
  double *px;
  px=calloc(1,sizeof(double));

  for (j=0; j<NBTESTS; j++) {
    switch(random() % NBCAS) {
      case 0: 
      case 1: 
      case 2:
        x = random() % 100;
        printf("Append de: %lf \n",x);
        vect_append(x,t1);
        break;
      case 3:
        nb=random()%(t1->actual_size+1);
        printf("Suppression des %d dernieres valeurs \n",nb);
        t1=vect_remove_nlast(nb,t1);
        break;
    }
    for(i=0; i<t1->actual_size; i++){
        px=(double*)t1->data[i];
        printf("%lf ",*px);
    }
    puts("");
  }
  printf("Liberation du tableau\n");
  t1=vect_delete(t1);
}