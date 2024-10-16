public class TestAffichageInfixe {

    public static void main(String[] args) { ExpAbstraite exp,expxx ;
// teste l’expression préfixée 42
        exp = new Constante (42) ; System.out.println(exp.toStringInfixe()) ;

         // teste l’expression préfixée * y 3
         exp = new BinaireMult(new Variable("y"), new Constante(3)) ;
         System.out.println(exp.toStringInfixe()) ;

         // teste l'expression + x x
        expxx = new BinairePlus(new Variable("x"), new Variable("x"));
        System.out.println(expxx.toStringInfixe());

        // teste l’expression préfixée * + x x 5

        exp = new BinaireMult(
                expxx, new Constante(5)
            );
        System.out.println(exp.toStringInfixe()) ; // et pas toStringInfixe ; comme ca !
// teste l’expression préfixée * -3.5 sin + a b
        exp = new BinaireMult(
                new Constante(-3.5),
                new UnaireSin(
                    new BinairePlus(
                        new Variable("a"), new Variable("b")
                        )
                    )
            );
         System.out.println(exp.toStringInfixe()) ; }
 }