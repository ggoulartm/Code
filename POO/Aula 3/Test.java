// dans le fichier Test.java
public class Test {
    public static void main(String [] args){
        A a1 = new A(); A a2 = new A();
        System.out.println("avant d'inc. a1 : " + a1.toString());
        a1.incrementerNbr();
        System.out.println("après inc. a1 : " + a1.toString());
        a2 = a1; a2.incrementerNbr();
        System.out.println("a2 = a1; inc. a2");
        System.out.println("a1 : " + a1.toString());
        System.out.println("a2 : " + a2); }
}