public class Variable extends ExpAbstraite {
    public String nom;
    public Variable(String nom) {
        this.nom = nom;
    }
    public String toStringInfixe(){
        return this.nom;
    }
}