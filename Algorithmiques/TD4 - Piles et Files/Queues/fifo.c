#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h> 
#include "fifo.h"

element_t* delete_data(element_t* e){
    free(e);
    return e;
}

void fprintf_data(double* v,FILE* fp){
    fprintf(fp,"%.2lf ",*v);
}

void element_print(element_t e){
  fprintf_data(&e,stdout);
}


// 2. prototypes des fonctions de l'API du TAD File

fifolink_t fifolink_new(){
  fifolink_t q = calloc(1,sizeof(fifolink_t));
  return q;
}

// Crée et retourne un file vide
fifo_t fifo_new(){
  fifo_t q;
  q = calloc(1,sizeof(fifo_t));
  q->head = fifolink_new();
  q->tail = q->head;
  return q;
}

// Détruit la file et retourne une file vide
fifo_t fifo_delete(fifo_t queue){
  delete_data(&queue->head->val);
  free(queue);
  return queue;
}

// Retourne 1 si la file  queue   est vide, 0 sinon
int fifo_is_empty(fifo_t queue){
  if(queue->head->next==NULL) return 1;
  return 0;
}

// Ajoute l'élément e à la file  queue  et retourne la nouvelle file
// Retourne NULL en cas d'erreur
fifo_t fifo_enqueue(element_t e, fifo_t queue){
  if(fifo_is_empty(queue)){
    queue->head->val=e;
    queue->head->next=queue;
    queue->tail=queue;
    return queue;
  }
  queue->tail = fifolink_new();
  queue->tail->next=queue->head->next;
  queue->tail->val = e;
  queue->head->next=queue->tail;
  return queue;
}

// Retourne l'élément en tête de file (sans l'enlever de la file)
// PRECONDITION : la file  queue  ne doit pas être vide
element_t fifo_peek(fifo_t queue){
  assert(! fifo_is_empty(queue));
  return queue->head->val;
}

// Enlève l'élément en tête de la file, et retourne cet élément
// PRECONDITION : la file pointée par  p_queue  ne doit pas être vide
element_t fifo_dequeue(fifo_t p_queue) {
  element_t e = p_queue->head->val;
  fifolink_t * newhead = p_queue->head->next;
  free(p_queue->head);
  p_queue->head = newhead;
  return e;
}

    // Remarque sur le prototype de fifo_dequeue() :
    // Cette fonction doit "retourner" 2 choses :
    //  - l'élément qui était en tête
    //  - et la file modifiée, dont on enlevée l'ancienne tête
    // Il faut donc, en C, utiliser un passage par adresse pour l'une
    // de ces deux valeurs (ici : la file)


// FONCTION optionnelle : affiche tous les éléments de la file, dans l'ordre
void fifo_print(fifo_t q) {
  if(fifo_is_empty(q)) {
    printf("The queue is empty\n");
    return ; // arrêt de la fonction dans la cas particulier file vide
  }
  fifolink_t p = q->head->next; // on commencera la boucle au PREMIER maillon
  while (p != q) {
    element_print(p->val);
    printf(" ; "); // pour séparer l'affichage des elts
    p = p->next;
  } ;
  // affichage du maillon de queue
  element_print(p->val);
  printf(" ; ");
  printf("\n"); // pour terminer par un retour chariot
}

// FONCTION optionnelle : compte le nombre d'éléments dans la file
int fifo_count(fifo_t q){
  if(fifo_is_empty(q)) {
    printf("The queue is empty\n");
    return 0; // arrêt de la fonction dans la cas particulier file vide
  }
  fifolink_t p = q->head->next; // on commencera la boucle au PREMIER maillon
  int count = 0; //the number of elements in q 
  while (p != q) {
    count++;
    p = p->next;
  } ;
  return count;
}