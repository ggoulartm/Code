#include "genericPointer.h"

table_t table_new(int n, void* (*delete_data)(void*), int (*equal_data)(void*,void*), void (*fprint_data)(void*, FILE*)) { int i;
  table_t ptab;

    // Allocation de la structure
  if ( (ptab=malloc(sizeof(*ptab))) ==NULL)
    return NULL;

    // Mise a jour des tailles max et actuelle
  ptab->max_size=n;
  ptab->actual_size=0;
  ptab->delete_data=delete_data;
  ptab->equal_data=equal_data;
  ptab->fprint_data=fprint_data;

    // Allocation des données
  if ( (ptab->data=calloc(n,sizeof(*(ptab->data)))) ==NULL) {
    free(ptab);
    return NULL;
  }
    // Fin creation et retour
  return ptab;
}

table_t table_append(void **e, table_t tab) {
    if (tab==NULL) return NULL;
    tab->actual_size++;
    tab->data[tab->actual_size-1]=e;
    return tab;
}

void table_delete(table_t table) {
    free(table);
}

void table_fprint(table_t table, FILE *fp) {
    if (table==NULL) return;
    int i; 
      for(i=0;i<table->actual_size; i++)
        fprintf(fp,"%.2lf ",table->data[i]);
}

void table_print(table_t table) {
    table_fprint(table,stdout);
}

table_t table_insertat(int i, void **e, table_t table) {
    if (table==NULL) return NULL;
    if (i < 0 && i >= table->actual_size) return NULL;
    table->data[i]=e;
    return table;
}

table_t table_removeat(table_t table, int i) {
    if (table==NULL) return NULL;
    if (i < 0 && i >= table->actual_size) return NULL;
    for(int j=i; j<table->actual_size-1;j++){ 
      table->data[j]=table->data[j+1];
    }
    table->actual_size--;
    return table;
}