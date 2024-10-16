public class UnaireCos extends ExpUnaire{
    private String cos;
    public UnaireCos(ExpAbstraite cos){
            this.cos = "Cos("+cos.toStringInfixe()+")";
    }
    public String toStringInfixe(){
            return this.cos;
    }
}