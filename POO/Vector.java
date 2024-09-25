class Vector {
    private Rational[] R;
    private int size;
    private int pos = 0;
    protected String str;
    public Vector(int size) {
        this.size = size;
        this.R = new Rational[size];
    }
    public void Insert(int a, int b) {
        Rational r = new Rational("v1",a,b);
        this.Insert(r,pos);
        this.pos++;
    }
    public void Insert(Rational R, int pos) {
        if(pos >= size || pos < 0) { return; }
        this.R[pos] = R;
    }
    public Rational[] Get() {
        return this.R;
    }
    public Rational get(int pos) {
        if(pos >= size || pos < 0) {
            System.out.println("Index (%d) dehors de la taille du vecteur", pos);
            return;
        }
        return this.R[pos];
    }
    public String toString() {
        this.str="";
        for(Rational r : this.R) {
            str = str + "(" + r.nom + "/" + r.denom + ")";
            if(this.R[size-1] == r) {
                return str;
            }
            str = str + ", ";
        }
        return str;
    }
}