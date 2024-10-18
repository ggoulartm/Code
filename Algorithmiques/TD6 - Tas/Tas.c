/*
    Université Grenoble Alpes - Grenoble INP
    Phelma - Filière SEOC
    Cours Algorithmiques
    Fichier: Tas.c
    Definition de tas
    Auteur: Gabriel Goulart Müller
    Dernière modification: 22/08/2003

    Le tas est une structure de données dont l'interet est de pouvoir trouver le maxima (resp. minima) en temps constant après avoir construit ce tas.

    Un tas est un arbre binaire complet (dont tous les niveaux sont completement remplis sauf eventuellement le dernier niveau) et possedant la proriété suivante : Tout noeud de l'arbre est plus grand que ses fils.

    Il est en général construit dans un tableau en profitant de l'aspect complet, qui induit les propriétés suivantes sur les positions des pères et des fils dans le tableau, rendant caduque l'usage de pointeurs explicite.

        - le pere d'un noeud d'indice i est à la position i/2
        - le fils gauche d'un noeud d'indice i est à la position 2*i+1
        - le fils droit d'un noeud d'indice i est à la position 2*i+2

*/
#include "Tas.h"

int equal_data(void* a, void* b){
    int Q = *((int*)a);
    int W = *((int*)b);
    if(Q == W) return 1;
    return 0;
}

void print_data(void* a, FILE* fp){
    fprintf(fp,"%d ",*((int*)a));
}

void delete_data(void* a){
    //free(a);
    return a;
}
// Creation d'un tas de n elements
heap_t heap_new(unsigned int n,void (*print_data)(void*,FILE*),
      void* (*delete_data)(void*),int (*equal_data)(void*,void*)) 
      {
        heap_t heap = vect_new(n,print_data,delete_data,equal_data);
        return heap;
      }
    
// Creation d'un tas de n elements default
heap_t heap_newD(unsigned int n) {
    heap_t heap = vect_new(n,print_data,delete_data,equal_data);
    return heap;
}
// Verification si le tas est vide
int heap_is_empty(heap_t tas){
    if(tas==NULL || tas->actual_size == 0) return 1;
    return 0;
}

// Ajout d'un element avec redimensionnement si nécessaire
int heap_add(void* valeur, heap_t tas){
    int exist = vect_lookup(tas,valeur);
    if(exist>=0){
        return exist;
    }
    tas = vect_append(valeur,tas);
    int index = tas->actual_size-1;
    while (index > 0 && tas->equal_data(tas->data+index, tas->data+HEAP_FATHER(index)) > 0) {
        vect_swap(tas, index, HEAP_FATHER(index));
        index = HEAP_FATHER(index);
    }
    return index;
}

// Obtenir l'extrema
void* heap_get_extrema(heap_t tas){
    return tas->data[0];
}

  // Supprimer le premier element et reoganisation du tas
int heap_delete_extrema(heap_t tas){
    return vect_remove_at(tas,0);
}

  // Fonction de vérification entre pere et fils
int heap_verification(heap_t tas) {
    int i;
    for (i=0; i < tas->actual_size/2; i++) {
    if (tas->equal_data(tas->data+i,tas->data+HEAP_LEFTSON(i))<0) 
        return i;
      if (HEAP_RIGHTSON(i)<tas->actual_size && 
            tas->equal_data(tas->data+i,tas->data+HEAP_RIGHTSON(i))<0) 
        return i;
    }
    return -1;
}

  // Suppression du tas
heap_t heap_delete(heap_t tas){
    return vect_delete(tas);
}

  // Affichage du tas
void heap_printf(heap_t tas) {
    if(tas==NULL) return;
    tas->fprint_data(tas->data[0],stdout);
    printf("\n");
    heap_printfils(tas,0,1,stdout);
}

    // Affichage des fils
void heap_printfils(heap_t tas, int i, int j,FILE* fp) {
    for(int k=i;k<=i+j;k++){
        if(HEAP_LEFTSON(k)<tas->actual_size && tas->data[HEAP_LEFTSON(k)!=NULL]){
            tas->fprint_data(tas->data[HEAP_LEFTSON(i)],fp);
        }
        if(HEAP_RIGHTSON(k)<tas->actual_size && tas->data[HEAP_RIGHTSON(k)!=NULL]){
            tas->fprint_data(tas->data[HEAP_RIGHTSON(i)],fp);
        }
    }
    printf("\n");
    if(HEAP_LEFTSON(i)<tas->actual_size) heap_printfils(tas,HEAP_LEFTSON(i),HEAP_RIGHTSON(j),fp);
}

// Affichage du tas dans un fichier
void heap_fprintf(heap_t tas,FILE* fp) {
    if(tas==NULL) return;
    tas->fprint_data(tas->data[0],fp);
    heap_printfils(tas,0,0,fp);
    printf("\n");
}
