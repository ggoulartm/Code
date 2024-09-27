#include "list.h"

// Creation d'une liste vide, avec les pointeurs de fonctions utiles
list_t list_new(void (*fprint_data)(void*,FILE*),
    void* (*delete_data)(void*),
    int (*equal_data)(void*,void*))
{
            list_t list;
              if ( (list=malloc(sizeof(*list))) ==NULL) return NULL;
            list->delete_data=delete_data;
            list->equal_data=equal_data;
            list->fprint_data=fprint_data;

            // Allocation des données
            if ( (list->data=calloc(1,sizeof(*(list->data)))) ==NULL) {
                free(list);
                return NULL;
            }
    
            link_t link;
            if ( (link=malloc(sizeof(*link))) ==NULL) return NULL;
            list->data=link;

            list->size=0;
            return list;
}

// Retourne VRAI si l est une liste vide
int list_is_empty(list_t l){
    return l->size == 0;
}
// Retourne VRAI si l est un maillon vide
int link_is_empty(link_t l){
    return l->data == NULL;
}

// Retourne l'élément en tête de liste : PRECONDITION : liste non vide
void* list_first(list_t l) {
    if(list_is_empty(l)) {return NULL;}
    return l->data->data;
}

// Ajoute l'élément e en tête des maillons et retourne cette tete
// Retourne la tete NON MODIFIEE en cas d'erreur
link_t link_add_first(void* e, link_t l){
    l->data=e;
    return l;
}

// Ajoute l'élément e en tête de liste et retourne cette liste
list_t list_add_first(void* e, list_t l){
    link_add_first(e,l->data);
    l->size++;
    return l;
}

// Supprime le maillon en tête des maillons et retourne les maillons
// PRECONDITION : maillons non vide
link_t link_del_first(link_t l , void* (*delete_data)(void*)){
    delete_data(l->data);
    return l->next;
}
// Supprime le maillon en tête de liste et retourne la nouvelle liste
// PRECONDITION : liste non vide
list_t list_del_first(list_t l ){
    if(l->data == NULL) return NULL;
    l->data->data = l->data->next->data;
    l->data->next = l->data->next->next;
    l->size--;
    return l;
}

// Retourne le nombre d'éléments (ou de maillons) de la liste
size_t list_length(list_t l) {
    return l->size;
}

// Affiche la liste a l'ecran, dasn un fichier.
void list_fprintf(list_t l, FILE* fp){
    if (l==NULL) return;
    return l->fprint_data(l,fp);
}
void list_printf(list_t l){
    if(l==NULL) return;
    return l->fprint_data(l,stdout);
}

// Libère toute la liste et retourne une liste vide
// Libere les elements avec delete_data si la fonction existe
list_t list_delete(list_t l){
    if(l==NULL) {return NULL;}
    return l->delete_data(l->data);
}

// Ajoute en queue de liste, eventuellement
list_t list_add_last(void* e, list_t l){
    link_t link = link_add_last(e,l->data);
    if(link==NULL) return NULL;
    l->size++;
    return l;
}
link_t link_add_last(void* e, link_t link){
    while(link->next != NULL){
        link = link->next;
    }            
    link_t linknext;
    if ( (linknext=malloc(sizeof(*link))) == NULL) return NULL;
    link->next = linknext;
    link->next->data=e;
    return link;
}
link_t last(link_t l){
    link_t link = l->next;
    while(link->next != NULL){
        link = link->next;
    }
    return link;
}
//Suppression en queue, eventuellement
list_t list_del_last(list_t l ){
    l->delete_data(last(l->data));
    l->size--;
    return l;
}
link_t link_del_last(link_t l, void* (*delete_data)(void*)){
    delete_data(last(l));
    return l;
}

// Recherche un element selon le critere compare. Retourne le maillon trouve ou NULL
link_t list_lookup(void* elem, list_t l, int(*compare)(void* e1, void* e2)){
    link_t link=l->data;
    while(compare(elem,link->data)==0){
        link = link->next;
    }
    return link;
}
// Recherche le premier maillon contenant e,
// au sens du equal_data ou de l'egalite de pointeurs si equal_data est NULL
// ou NULL si e n'est pas dans la liste       
link_t list_find(void* e, list_t l){
    link_t link=l->data;
    while(l->equal_data(e,link->data)==0){
        link = link->next;
    }
    return link;
}

// Suppression de l'element param, au sens de equal_data
list_t list_remove(void* param, list_t l){
    link_t link = list_find(param,l);
    link->data=link->next->data;
    link->next=link->next->next;
    l->delete_data(link->next);
    return l;
}

  // Les visiteurs
void list_simple_visit(list_t l, void (*exec)(void*,void*), void* param){
    link_t link = l->data;
    while(link->next != NULL){
        exec(link->data,param);
        link=link->next;
    }
}
void list_visit(list_t l, int (*exec_on_value)(void*,void*), int (*exec_on_link)(list_t,void*),void* param){
    link_t link = l->data;
    while(link->next != NULL){
        if(exec_on_value(link->data,param)!=0) exec_on_link(l,link->data);
        link=link->next;
    }
}