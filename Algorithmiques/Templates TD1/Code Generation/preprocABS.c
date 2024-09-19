#define ABS(x) ((x>0) ? (x) : -(x))

// pre-processateur example

int main() {
	int i,j,k,l,m;
	double x,y;
	i=10; j=-5;
	k=ABS(i);
	l=ABS(j);
	m=ABS(i+j);

	x=-3.15;
	y=ABS(x);
    return 0;
}