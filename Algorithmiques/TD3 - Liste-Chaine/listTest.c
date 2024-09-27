#include "list.c"

void listprint(void* l, FILE* fp){
    if (l==NULL) return;
    list_t list = (list_t) l;
    int i; 
    double* px;
    px= malloc(sizeof(*px));
    link_t next;
    next=malloc(sizeof(link_t));
    next=list->data;
      for(i=0;i<=list->size; i++){
        if(next==NULL) break;
        *px=*(double*)next->data;
        fprintf(fp,"%.2lf ",*px);
        next=next->next;
      }
}

int main(){
    list_t l = list_new(listprint,NULL,NULL);
    double* px;
    px= malloc(sizeof(*px));
    *px=1;
    list_add_first(px,l);
    double* px1;
    px1= malloc(sizeof(*px1));
    *px1=2;
    list_add_last(px1,l);
    double* px2;
    px2= malloc(sizeof(*px2));
    *px2=3;
    list_add_last(px2,l);
    list_printf(l);
}