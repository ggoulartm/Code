public class Canard extends Animal {
    private String colorOfPlumes;
    public Canard(String name, int ag) {
        super(name,ag);
        this.colorOfPlumes = "green";
    }
    public Canard(String name, int ag, String rc){
        super(name,ag);
        this.colorOfPlumes=rc;
    }
    public void crier(){
        System.out.println("quac quac");
    }
    public String getCouleurPlumes(){
        return this.colorOfPlumes;
    }
}