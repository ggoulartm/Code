public class Animal {
    private String name;
    private int age;

    public Animal(String name, int age){
        this.name = name;
        this.age = age;
    }

    public void crier(){
        System.out.println("crier:");
    }
    public String getCouleurPlumes(){
        return "Pas de plumes la";
    }
    protected void setAge(int ag){
        this.age=ag;
    }
    protected void setName(String sp){
        this.name=sp;
    }
}