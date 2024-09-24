import java.util.Random;

// 1b écrivez un programme de test qui crée une fraction 3/2 et l'affiche dans la console
public class TestRational {
    public static void main(String[] args) {
        System.out.println("-- Test 1 begins: creating rational --");
        int x,y;
        float z;
        x = new Random().nextInt(10);
        y = new Random().nextInt(10);
        Rational rational = new Rational("Rational 1",x,y);
        System.out.println(rational);
        System.out.println("----------- SUCCESS -----------");
        System.out.println("----------- Test 1 ended ----------- \n\n");

        System.out.println("-- Test 2 begins: adding rationals --");
        x = new Random().nextInt(10);
        y = new Random().nextInt(10);
        Rational rational2 = new Rational("Rational 2",x,y);
        z=rational2.Real();
        System.out.println("To be added: "+rational);
        System.out.println("To be added: "+rational2);
        rational2.add(rational);
        System.out.println("Result: "+rational2);
        if(rational2.Real()==z+rational.Real()){
            System.out.println("----------- SUCCESS -----------");
        } else {
            System.out.println("Expected result: " + z*rational.Real()
                    + "\nInsted we got: " + rational2.Real());
            System.out.println("----------- FAILURE -----------");
        }
        System.out.println("----------- Test 2 ended -----------\n\n");


        System.out.println("-- Test 3 begins: multiply rational --");
        x = new Random().nextInt(10);
        y = new Random().nextInt(10);
        Rational rational3 = new Rational("Rational 3",x,y);
        z=rational3.Real();
        System.out.println("To be multiplied: "+rational);
        System.out.println("To be multiplied: "+rational3);
        rational3.mult(rational);
        System.out.println("Result:"+rational);
        if(rational3.Real()==z*rational.Real()){
            System.out.println("----------- SUCCESS -----------");
        } else {
            System.out.println("Expected result: " + z*rational.Real() +
                    "\nInsted we got: " + rational3.Real());
            System.out.println("----------- FAILURE -----------");
        }
        System.out.println("----------- Test 3 ended -----------\n\n");


        System.out.println("-- Test 4 begins: adding rational --");
        x = new Random().nextInt(10);
        y = new Random().nextInt(10);
        Rational rational4 = new Rational("Rational 4",x,y);
        z=rational4.Real();
        System.out.println("To be added: "+rational2);
        System.out.println("To be added: "+rational4);
        rational4.add(rational2);
        System.out.println("Result: "+rational2);
        if(rational4.Real()==(z+rational2.Real())){
            System.out.println("----------- SUCCESS -----------");
        } else {
            System.out.println("Expected result: " + z*rational2.Real() +
                    "\nInsted we got: " + rational4.Real());
            System.out.println("----------- FAILURE -----------");
        }
        System.out.println("----------- Test 4 ended -----------\n\n");


        System.out.println("-- Test 5 begins: multiply rational --");
        x = new Random().nextInt(10);
        y = new Random().nextInt(10);
        Rational rational5 = new Rational("Rational 5",x,y);
        z=rational5.Real();
        System.out.println("To be multiplied: "+rational3);
        System.out.println("To be multiplied: "+rational5);
        rational5.mult(rational3);
        System.out.println("Result: "+rational3);
        if(rational5.Real()==z*rational3.Real()){
            System.out.println("----------- SUCCESS -----------");
        } else {
            System.out.println("Expected result: " + z*rational3.Real() +
                    "\nInsted we got: " + rational5.Real());
            System.out.println("----------- FAILURE -----------");
        }
        System.out.println("----------- Test 5 ended -----------");
    }
}