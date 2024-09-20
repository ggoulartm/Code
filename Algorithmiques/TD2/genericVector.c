/*
Université Grenoble Alpes - Grenoble INP / Phelma
Disciplina de Algoritmos - Filière SEOC
Author: Gabriel Goulart Müller
Data 20/09/2024

Travail Dirigé 2 - TD2
Generic Types - Tableaux redimensionnables
*/

#include "genericVector.h"

    vect_t vect_new(unsigned int n, void (*print_data)(void*,FILE*), 
            void* (*delete_data)(void*),int (*equal_data)(void*,void*)) {
        vect_t vectTable;
            // Allocation de la structure
        if ( (vectTable=malloc(sizeof(*vectTable))) ==NULL)
        return NULL;

        // Mise a jour des tailles max et actuelle
        vectTable->max_size=n;
        vectTable->actual_size=0;

        // Allocation des données
        if ( (vectTable->data=calloc(n,sizeof(*(vectTable->data)))) == NULL) {
            free(vectTable);
            return NULL;
        }

        //Mise a jour des metodes
        vectTable->delete_data=delete_data;
        vectTable->equal_data=equal_data;
        vectTable->fprint_data=print_data;

        // Fin creation et retour
        return vectTable;
    }

    vect_t vect_append(double e, vect_t table) {
        if (table==NULL) return NULL;
        if (table->actual_size == table->max_size) {
            void **tmp;
            tmp=realloc(table->data,(table->max_size*2)*sizeof(*(table->data)));
            if (tmp == NULL) {
                // your realloc didn't work and strp->data still points to the
                // the original location
                printf("EMEMORY");
                return NULL;
            }
            table->data = tmp;
            table->max_size=2*table->max_size;
        }
        double* px;
        px=calloc(1,sizeof(double));
        *px=e;
        table->data[table->actual_size]=px;
        table->actual_size++;
        return table;
    }

    vect_t vect_remove_at(vect_t table, int i) {
        if (table==NULL) return NULL;
        if (i < 0 && i >= table->actual_size) return NULL;
        for(int j=i; j<table->actual_size-1;j++){ 
            table->data[j]=table->data[j+1];
        }
        table->actual_size--;
        return table;
    }

    vect_t vect_remove_nlast(int n, vect_t table)  {
        for(int i = 0; i<n; i++){
                if(table->actual_size==0) return table;
                table->actual_size--;
        }
       return table;
    }

    vect_t vect_delete(vect_t table)  {
        if (table==NULL) return NULL;
            // A t on passe une fonction de liberation des elements ?
        if (table->delete_data)
            // On libere les elements grace à notre pointeur
            for (int i=0; i<table->actual_size; i++)
            table->delete_data(table->data[i]);

        // On libere le tableau et la structure allouée
        free(table->data);
        free(table);
        return NULL;
    }

    int vect_lookup(vect_t table, double x) {
        int pos = -1;
        for(int i=0; i<table->actual_size; i++) {
            if(table->equal_data(table->data[i],&x)) {
                pos=i;
                return pos;
            }
        }
        return pos;
    }