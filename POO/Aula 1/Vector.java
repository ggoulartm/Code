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
        Rational r = new Rational("v"+pos,a,b);
        this.Insert(r,pos);
        this.pos++;
        this.size++;
    }
    public void Insert(Rational R, int pos) {
        if(pos >= size || pos < 0) { return; }
        this.R[pos] = R;
    }
    public Rational[] Get() {
        return this.R;
    }
    public int len() {
        return this.R.length;
    }
    public Rational get(int pos) {
        if(pos >= size || pos < 0) {
            System.out.printf("Index (%d) dehors de la taille du vecteur\n", pos);
            return R[0];
        }
        return this.R[pos];
    }
    public Vector mult(int a, int b) {
        System.out.println("Multiplier du vecteur tous les rationels par ("+a+"/"+b+")");
        Rational r = new Rational("multiplier",a,b);
        return this.mult(r);
    }
    public Vector mult(Rational r) {
        for(Rational RationalUnit: this.R) {
            RationalUnit.mult(r);
        }
        return this;
    }
    public Vector add(int a, int b) {
        System.out.println("Ajouter du vecteur tous les rationels par ("+a+"/"+b+")");
        Rational r = new Rational("adder",a,b);
        return this.add(r);
    }
    public Vector add(Rational r) {
        for(Rational RationalUnit: this.R) {
            RationalUnit.add(r);
        }
        return this;
    }
    public Vector add(Vector v) {
        if(v.len() != this.R.length) { System.err.println("Vecteur de longueur different"); return this;}
        for(int i = 0; i < this.R.length; i++) {
            this.R[i].add(v.get(i));
        }
        return this;
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