#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tri.h"

int* randominttabgeneration(unsigned n)   {
    int* donnees_test = malloc(n * sizeof(*donnees_test));
    for (size_t i = 0; i < n; i++)
        donnees_test[i] = random() % n;
        return donnees_test;
}

int compar(void* a, void*b) { return *(int*)a-*(int*)b;}

main() { clock_t avant, apres;
    double temps1,temps2;
    int k, total_number=1000000;
    int *t1, *t2;

    /* Ouverture d'un fichier contenant les temps de calcul */
    FILE* fp =fopen("tempstri.dat","w");

    /* k est le nombre d’elements a trier */
    for (k=1; k<=total_number; k+=k) {
            /* génération des nombres aléatoires et copie dans le deuxieme tableau */
        t1=randominttabgeneration(k);
        t2=malloc(k*sizeof(t2));
        memcpy(t2,t1,k*sizeof(*t1));

                    /* Tri par quick sort , version de la bibliotheque C */
        avant=clock();      
        qsort(t1,k,sizeof(*t1),compar);      
        apres=clock();

            /* Le temps de qsort est donne par apres-avant/CLOCKS_PER_SEC. */
        temps1=((double)apres - avant)/CLOCKS_PER_SEC;

            /* Tri par ma fonction heap_sort*/
        avant = clock();      
        //Qsort(t2,0,k);
        hsort(t2,k);
        apres = clock();
        temps2=((double)apres - avant)/CLOCKS_PER_SEC;

            /* Affichage des temps des 2 tris dans le fichier */
        if (fp) {
            fprintf(fp,"%d\t%lf\t%lf\n", k, temps1, temps2);
        }
        free(t1);
        free(t2);
    }


    /* Affichage des 2 courbes contenues dans le fichier tempstri.dat avec le logiciel gnuplot */
    if (fp) {
    fclose(fp);
    system("gnuplot -p -e \"set logscale x; f(x) = a * x * log(x); fit f(x) 'tempstri.dat' u 1:2 via a;"
                "plot 'tempstri.dat' u 1:2 with line lt 4 title 'quickSort', a * x * log(x)  with line lt 6 title 'Fit quick';"
                "g(x) = b * x * log(x);fit g(x) 'tempstri.dat' u 1:3 via b;"
                "replot 'tempstri.dat' u 1:3 with line lt 2 title 'MonTriHeap', b * x * log(x)  with line lt 8 title 'Fit Heap'; quit\"");
    }
}