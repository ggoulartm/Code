#define SWAP(x,y,type) {(type tmp; tmp=x; x=y; y=tmp;)}

int main() {
    int i,j;
    double x,y;
    i=10; j=5;
    SWAP(i,j,int);
    x=3.16; y=10.9;
    SWAP(x,y,double);
}