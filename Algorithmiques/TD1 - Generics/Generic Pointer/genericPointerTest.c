#include "genericPointer.c"


int main() { int i;
  double* px;
    // tab sera un tableau de 10 réels double
  table_t tab;

    // Creation du tableau
  tab=table_new(10,NULL,NULL,NULL);

    // Ajout de 5 elements aléatoires
  for( i=0; i<5; i++)  {
      // Creation d'un reel
    px= malloc(sizeof(*px));
    *px = random() % 100;
      // Ajout du reel à la fin et mise a jour de la taille
    printf("Ajoutant %.2lf au tableau\n", *px);
    tab = table_append(px, tab);
  }

  table_print(tab);
  puts("");
}