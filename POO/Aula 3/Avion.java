public class Avion {
    private int nbPassagers;
    private Moteur m;
    public Avion(int nbrP, Moteur m) {
        this.nbPassagers = nbrP;
        this.m = m;
    }
    public Moteur getMoteur () {
        return this.m;
    }
    public int getNbPassagers() {
        return nbPassagers;
    }
    @Override
    public String toString () {
        return "nbr de passagers= " + nbPassagers + " moteur " + m ;
    }
    public static void main(String [] args){ Moteur m = new Moteur();
        Avion a = new Avion(12, m); m.setPuissance(1);
        System.out.println("a, début : " + a);
        Moteur m2 = a.getMoteur();
        m2.setPuissance(0);
        int n = a.getNbPassagers();
        n = 0;
        System.out.println("a, fin : " + a); }
}

//printed:
//a, début : nbr de passagers= 12 moteur puissance= 1000
//a, fin : nbr de passagers= 12 moteur puissance= 1000