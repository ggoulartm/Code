public class Animal {
    private String specie;
    private int age;

    public Animal(String sp, int ag, String rc){
        this.specie=sp;
        this.age=ag;
    }
    public void crier(){
        System.out.println("crier");
    }
    protected void setAge(int ag){
        this.age=ag;
    }
    protected void setSpecie(String sp){
        this.specie=sp;
    }
}