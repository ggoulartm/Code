public class TestVector {
    public static void main(String[] args) {
        Vector vR = new Vector(3);
        vR.Insert(1,2); vR.Insert(1,2); vR.Insert(1,3);
        System.out.println(vR);
        System.out.println(vR.get(0));
        vR.get(1).mult(vR.get(2));
        System.out.println(vR.get(1));
        System.out.println(vR.mult(2,3));
        System.out.println(vR.add(2,3));
        Vector vR2 = new Vector(2);
        System.out.println(vR.add(vR2));
        Vector vR3 = new Vector(3);
        vR3.Insert(1,2); vR3.Insert(1,2); vR3.Insert(1,3);
        System.out.println(vR.add(vR3));
    }
}