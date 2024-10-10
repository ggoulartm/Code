public class Canard extends Animal {
    private String colorOfPlumes;
    public Canard(String animal, int ag, String rc){
        setSpecie(animal);
        setAge(ag);
        this.colorOfPlumes=rc;
    }
    public String getCouleurPlumes(){
        return this.colorOfPlumes;
    }
}