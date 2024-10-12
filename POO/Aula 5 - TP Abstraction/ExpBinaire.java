public abstract class ExpBinaire extends ExpAbstraite {
    ExpAbstraite opGauche;
    ExpAbstraite opDroite;
    public ExpBinaire(ExpAbstraite a, ExpAbstraite b){
        this.opGauche = a;
        this.opDroite = b;
    }
}