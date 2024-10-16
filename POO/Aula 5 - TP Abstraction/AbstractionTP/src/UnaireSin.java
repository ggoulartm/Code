public class UnaireSin extends ExpUnaire{
    private String sin;
    public UnaireSin(ExpAbstraite sin){
        this.sin = "Sin("+sin.toStringInfixe()+")";
    }
    public String toStringInfixe(){
        return this.sin;
    }
}