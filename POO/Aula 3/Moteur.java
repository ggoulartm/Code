// dans le fichier Moteur.java
public class Moteur {
    private int puissance;
    public Moteur(int puissance) {
        this.puissance = puissance; }
    /** Constructeur par défaut. Puissance par défaut : 1000 */
    public Moteur () { this(1000);
    }
    public Moteur(Moteur other) { this.puissance = other.puissance;
    }
    public void setPuissance(int puisance) { this.puissance = puissance;
    }
    @Override
    public String toString () {
        return "puissance= " + puissance; }
}