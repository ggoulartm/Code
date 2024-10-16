public class Constante extends ExpAbstraite {
    private double valeur;
    public Constante(double valeur) {
        this.valeur = valeur;
    }
    public Constante(int valeur) {
        this.valeur = (double) valeur;
    }
    public String toStringInfixe() {
        return ""+this.valeur;
    }
}