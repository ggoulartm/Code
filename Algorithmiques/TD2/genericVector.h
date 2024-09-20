/*
Université Grenoble Alpes - Grenoble INP / Phelma
Disciplina de Algoritmos - Filière SEOC
Author: Gabriel Goulart Müller
Data 20/09/2024

Travail Dirigé 2 - TD2
Generic Types - Tableaux redimensionnables
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _vect_t {
  void* * data;
  unsigned int max_size;
  unsigned int actual_size;
  }  * vect_t;

    vect_t vect_new(unsigned int n) ;
    vect_t vect_append(double e, vect_t table) ;
    vect_t vect_remove_nlast(int n, vect_t table)  ;
    vect_t vect_delete(vect_t table)  ;