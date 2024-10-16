public class BinaireMult extends ExpBinaire {
    public BinaireMult(ExpAbstraite v1, ExpAbstraite v2) {
        super(v1,v2);
    }
    public String toStringInfixe(){
        return "("+this.opGauche.toStringInfixe()+"*"+this.opDroite.toStringInfixe()+")";
    }
}