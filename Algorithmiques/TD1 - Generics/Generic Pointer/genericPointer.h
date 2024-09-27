/*
Université Grenoble Alpes - Grenoble INP / Phelma
Disciplina de Algoritmos - Filière SEOC
Author: Gabriel Goulart Müller
Data 16/09/2024

Travail Dirigé 1 - TD1
Generic Types - Genericité par void pointers
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct  {
    void* * data  ;         // Les données du tableau : un pointeur vers des pointeurs
    size_t max_size;      // La taille maximale
    size_t actual_size;    // La taille actuelle

    void* (*delete_data)(void*); // Un pointeur vers la fonction qui libère les éléments
    int (*equal_data)(void*,void*); // Comment tester l'egalite de 2 elements
    void (*fprint_data)(void*, FILE*); // Comment afficher un éléments
} * table_t;

