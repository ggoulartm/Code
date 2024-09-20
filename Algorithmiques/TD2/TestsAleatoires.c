#include "genericVector.c"

#define NBTESTS 10000
#define NBCAS 4

int equal_double(void* a, void* b) {
    int i;
    //i=calloc(1,sizeof(int));
    if ((double*)a==(double*)b) {
        i=1;
        return i;
    }
    i=0;
    return i;
}

// Fonction de liberation des réels
void* double_delete(void *data) {
  double* p = (double*)data;
  free(p);
  return NULL;
}

// Programme de tests aleatoire
// 3 fois plus d'ajout que de suppression
int main() {
  vect_t t1 = vect_new(2,NULL,double_delete,&equal_double);
  double x;
  int i,j,nb;
  double *px;
  px=calloc(1,sizeof(double));

  for (j=0; j<NBTESTS; j++) {
    switch(random() % NBCAS) {
      case 0: 
        if(t1->actual_size==0) break;
        nb=random()%(t1->actual_size);
        printf("Suppression de valeur en position %d \n",nb);
        vect_remove_at(t1,nb);
        break;
      case 1: 
        x = random() % 100;
        printf("Recherce de l'element: %.2lf \n",x);
        int pos = vect_lookup(t1,x); 
        if (pos != -1){
            printf("Element %.2lf trouvé à la position %d \n",x, pos);
            break;
        }
        printf("Element pas trouvé \n");
        break;
      case 2:
        x = random() % 100;
        printf("Append de: %.2lf \n",x);
        vect_append(x,t1);
        break;
      case 3:
        if(t1->actual_size==0) break;
        nb=random()%(t1->actual_size);
        printf("Suppression des %d dernieres valeurs \n",nb);
        t1=vect_remove_nlast(nb,t1);
        break;
    }
    for(i=0; i<t1->actual_size; i++){
        px=(double*)t1->data[i];
        printf("%.2lf ",*px);
    }
    puts("");
  }
  printf("Liberation du tableau\n");
  t1=vect_delete(t1);
}