#include "pile.c"

int main(int argc, char* argv[]){
    lifo_t pile;
    pile = lifo_new(NULL,NULL,NULL);
    lifo_is_empty(pile);
    consulter(pile);
    return 0;
}