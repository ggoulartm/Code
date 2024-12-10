class Test {
    public static void main(String[] args) {
        // Create input elements
        Entree input1 = new Entree("Input1");
        Entree input2 = new Entree("Input2");

        // Create a NOT gate (Inverser)
        Inverser notGate = new Inverser("NOT1", input1);

        // Create AND and OR gates
        PorteEt andGate = new PorteEt("AND1", input1, input2);
        PorteOu orGate = new PorteOu("OR1", notGate, input2);

        // Print the elements
        System.out.println("NOT Gate: " + notGate);
        System.out.println("AND Gate: " + andGate);
        System.out.println("OR Gate: " + orGate);
    }
}

class TestCircuit {
    public static void main(String[] args) {
        // Create input elements
        Entree input1 = new Entree("Input1");
        Entree input2 = new Entree("Input2");
        Entree input3 = new Entree("Input3");

        // Create NOT gates (Inverters)
        Inverser notGate1 = new Inverser("NOT1", input1);
        Inverser notGate2 = new Inverser("NOT2", input3);

        // Create AND gates
        PorteEt andGate1 = new PorteEt("AND1", input1, input2); // AND of Input1 and Input2
        PorteEt andGate2 = new PorteEt("AND2", notGate1, input3); // AND of NOT(Input1) and Input3

        // Create OR gates
        PorteOu orGate1 = new PorteOu("OR1", andGate1, andGate2); // OR of AND1 and AND2
        PorteOu orGate2 = new PorteOu("OR2", input2, notGate2); // OR of Input2 and NOT(Input3)

        // Combine gates into a final circuit
        PorteEt finalAndGate = new PorteEt("FinalAND", orGate1, orGate2);

        // Display the structure
        System.out.println("Complex Circuit Structure:");
        printElement(input1);
        printElement(input2);
        printElement(input3);
        printElement(notGate1);
        printElement(notGate2);
        printElement(andGate1);
        printElement(andGate2);
        printElement(orGate1);
        printElement(orGate2);
        printElement(finalAndGate);
    }

    /**
     * Helper method to print an element and its sources (if applicable).
     */
    private static void printElement(Element element) {
        System.out.println("Element: " + element);
        if (element instanceof Inverser) {
            System.out.println("  Source: " + ((Inverser) element).getSource());
        } else if (element instanceof PorteBinaire) {
            PorteBinaire binaryGate = (PorteBinaire) element;
            System.out.println("  Source 1: " + binaryGate.getSource1());
            System.out.println("  Source 2: " + binaryGate.getSource2());
        }
    }
}
