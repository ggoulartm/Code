// on commence doucement
// 1a créer une classe Rational, qui possède deux attributs entiers num et denom
class Rational {
    public int nom;
    public int denom;
    public Rational(int nom, int denom) {
        this.nom = nom;
        this.denom = denom;
    }
    public String toString() {
        return "Le rational est (" + this.nom
                + "/" + this.denom + ")";
    }
}


