// Version: TD7.1
#include "vect.h" 
      /* partitionner le tableau `tab` entre les indices `gauche`et `droite`
    int partitionner(vect_t tab, int gauche, int droit);
      tri recursif du tableau `tab` entre les indices `gauche`et `droite`
    void quick_sortrec(vect_t tab, int gauche, int droit);
      Tri du tableau `tab` entier (fonction wrapper cachant les autres paramètres à l'utilisateur) */
    void Qsort(int arr[], int low, int high) ;
    void quicksort(vect_t tab);

      /*Fusion des 2 demi tableaux triés de `tab` compris entre les indices `gauche` et `droit` à l'aide du tableau `tmp`*/
    void fusion(vect_t tab, vect_t tmp, size_t gauche, size_t droit);
      /* Tri récursif du tableau `tab` entre les indices `gauche` et `droit` à l'aide du tableau `tmp` */
    void _trifusionrec(vect_t tab, vect_t tmp, size_t gauche, size_t droit);
      /* Tri du tableau `tab` entier (fonction wrapper cachant les autres paramètres à l'utilisateur) */
    void merge_sort(vect_t tab);

      /* Tri par tas du tableau `tab`*/
    void hsort(int arr[], int n);
    void heap_sort(vect_t tab);
