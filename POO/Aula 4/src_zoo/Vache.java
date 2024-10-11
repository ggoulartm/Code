public class Vache extends Animal {
    private int poids;

    public Vache(String name, int age) {
        super(name,age);
        this.poids = age*30;
    }
    public Vache(String name, int age ,int poids) {
        super(name,age);
        this.poids = poids;
    }
    public void crier(){
        System.out.println("muuuuuuū");
    }
}