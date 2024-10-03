import java.util.Random;

public class TestRational {
    public static int NBTEST = 1000;
    public static void Test(float ExpectedResult, float Result) {
        if(ExpectedResult<(Result+0.001) && ExpectedResult>(Result-0.001)){
            System.out.println("----------- SUCCESS -----------");
        } else {
            System.out.println("Expected result: " + ExpectedResult +
                    "\nInsted we got: " + Result +
                    "\n----------- FAILURE -----------");
            System.exit(2);
        }
    }
    public static void main(String[] args) {
        int x,y;
        float z;

        System.out.println("-- Test 0 begins: creating rational --");
        x = new Random().nextInt(10);
        y = new Random().nextInt(10);
        Rational rational1 = new Rational("Rational 1",x,y);
        System.out.println(rational1);
        Test(x,x);
        x = new Random().nextInt(10);
        y = new Random().nextInt(10);
        Rational rational2 = new Rational("Rational 2",x,y);
        System.out.println(rational2);
        Test(x,x);
        System.out.println("----------- Test 0 ended ----------- \n\n");

        for (int i = 0; i < NBTEST; i++) {
            System.out.println("-- Test "+i+" begins: addition rational --");
            x = new Random().nextInt(10);
            y = new Random().nextInt(10);
            rational1 = new Rational("Rational 1",x,y);
            x = new Random().nextInt(10);
            y = new Random().nextInt(10);
            rational2 = new Rational("Rational 2",x,y);

            z=rational1.Real();
            System.out.println("To add: "+rational1);
            System.out.println("To be added: "+rational2);
            rational1.add(rational2);
            System.out.println("Result: "+rational1);
            Test((z+rational2.Real()),rational1.Real());
            System.out.println("----------- Test "+i+" ended -----------\n\n");

            System.out.println("-- Test "+i+" begins: multiply rational --");
            x = new Random().nextInt(10);
            y = new Random().nextInt(10);
            rational1 = new Rational("Rational 1",x,y);
            x = new Random().nextInt(10);
            y = new Random().nextInt(10);
            rational2 = new Rational("Rational 2",x,y);
            z=rational1.Real();
            System.out.println("To multiply: "+rational1);
            System.out.println("To be multiplied: "+rational2);
            rational1.mult(rational2);
            System.out.println("Result: "+rational1);
            Test((z*rational2.Real()),rational1.Real());
            System.out.println("----------- Test "+i+" ended -----------\n\n");
         }
    }
}