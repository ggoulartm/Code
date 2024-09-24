// on commence doucement
// 1a créer une classe Rational, qui possède deux attributs entiers num et denom
class Rational {
    public String Nom;
    public int nom;
    public int denom;
    public Rational(String Nom, int nom, int denom) {
        this.Nom = Nom;
        if(denom == 0) {
            this.nom = nom;
            this.denom = 1;
            System.err.println("Il est interdit de créer un rationel avec denominateur 0");
            System.err.println("Le rationel a été creé en ayant 1 comme denominateur");
            return;
        }
        this.nom = nom;
        this.denom = denom;
        this.reduce();
    }
    public String toString() {

        if(denom == 1) {
            return "Le rational qui s'appelle "+ this.Nom
                    +" est un nombre entier: " + this.nom;
        }
        return "Le rational qui s'appelle "+ this.Nom
                +" est (" + this.nom
                + "/" + this.denom + ")";
    }
    public void mult(Rational r) {
        this.nom = this.nom * r.nom;
        this.denom = this.denom * r.denom;
        this.reduce();
    }

    public void add(Rational r) {
        if (this.denom == r.denom) {
            this.nom = this.nom + r.nom;
            this.reduce();
            return;
        }
        this.nom = this.nom * r.denom + this.denom * r.nom;
        this.denom = this.denom * r.denom;
        this.reduce();
    }

    public void reduce() {
        pgcd(this.nom, this.denom);
    }

    public int pgcd(int a, int b) {
        if(b==0){
            if(a!=0){
                this.nom = this.nom / a;
                this.denom = this.denom / a;
            }
            return a;
        }
        return pgcd(b, a%b);
    }

    public float Real() {
        return (float)this.nom/(float)this.denom;
    }
}


