/*
Université Grenoble Alpes - Grenoble INP / Phelma
Disciplina de Algoritmos - Filière SEOC
Author: Gabriel Goulart Müller
Data 20/09/2024

Travail Dirigé 2 - TD2
Generic Types - Tableaux redimensionnables
*/

#include <stdio.h>

typedef struct _vect_t {
  void* * data;
  int max_size;
  int actual_size;

  void (*fprint_data)(void*,FILE*);
  void* (*delete_data)(void*);
  int (*equal_data)(void*,void*);
  }  * vect_t;

    vect_t vect_new(int n,void (*print_data)(void*,FILE*),
          void* (*delete_data)(void*),int (*equal_data)(void*,void*)) ;
    vect_t vect_append(void* e, vect_t table) ;
    void vect_swap(vect_t table, int i, int j) ;
    int vect_lookup(vect_t table, void* x) ;
    vect_t vect_insertat(int i, void *e, vect_t table);
    vect_t vect_remove_nlast(int n, vect_t table)  ;
    int vect_remove_at(vect_t table, int i)  ;
    vect_t vect_delete(vect_t table)  ;
    vect_t vect_fprintf(vect_t table,FILE* f)  ;
    void *vect_get_last(vect_t table)  ;
