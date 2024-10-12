public class BinairePlus extends ExpBinaire {
    public BinairePlus(ExpAbstraite v1, ExpAbstraite v2) {
        super(v1,v2);
    }
    public String toStringInfixe(){

        return "("+this.opGauche.toStringInfixe()+"+"+this.opDroite.toStringInfixe()+")";

    }
}