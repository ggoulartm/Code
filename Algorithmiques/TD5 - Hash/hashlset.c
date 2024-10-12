#include "hashlset.h"

      // prototypes des fonctions
      // Creation d'un ensemble vide de taille n
    hashlset_t hashlset_new(int n, unsigned int (*fhachage)(void * ),
          void (*print_key)(void*,FILE*),
          void* (*delete_key)(void*),
          int (*compare_key)(void* e1, void* e2) )
        {
            // Allocation de la structure
            hashlset_t hashlset;
            if ( (hashlset=calloc(n,sizeof(*hashlset))) ==NULL) return NULL;
            hashlset->delete_key=delete_key;
            hashlset->compare_key=compare_key;
            hashlset->print_key=print_key;
            hashlset->hachage=fhachage;

            // Allocation des données
            if ( (hashlset->data=calloc(1,sizeof(*(hashlset->data)))) ==NULL) {
                free(hashlset);
                return NULL;
            }
    
            // Allocation du premier maillon
            link_t link;
            if ( (link=calloc(1,sizeof(*link))) ==NULL) return NULL;
            hashlset->data=link;

            hashlset->size=0;
            return hashlset;
        }

    // Destruction de l'ensemble
    hashlset_t hashlset_delete(hashlset_t table){
        link_t link=table->data;
        while(link!=NULL){
            link_t next=link->next;
            table->delete_key(link->data);   
            link=next;
        }
        free(table->data);
    }
    
    //Ajout d'un element
    int hashlset_put(void* key, hashlset_t table){
        unsigned int h = table->hachage(key);
        link_t link=table->data;
        while(link->next!=NULL){
            if (table->compare_key(link->data,h)==0) return 1;
            link=link->next;
        }
        link_t new_link;
        if ( (new_link=malloc(sizeof(*new_link))) ==NULL) return 0;
        new_link->data=h;
        new_link->next=NULL;
        link->next=new_link;
        return 1;
    }
    // Presence de l'element
    int hashlset_find_key(void* key, hashlset_t table){
        unsigned int h = table->hachage(key);
        if(table->data[h]!=NULL) return 1;
        return 0;
    }
    // Suppression de l'element
    int hashlset_remove_key(void* key, hashlset_t table){
        unsigned int h = table->hachage(key);
        table->delete_key(table->data[h]);
        return 1;
    }
    // Affichage de l'ensemble
    void hashlset_fprintf(hashlset_t table, FILE*fp){
        link_t link=table->data;
        while(link!=NULL){
            table->print_key(link->data,fp);
            link=link->next;
        }
    }