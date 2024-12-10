import java.util.HashMap;
import java.util.Map;
import java.util.Set;

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
        // Create inputs
        Entree input0 = new Entree("Input0");
        Entree input1 = new Entree("Input1");
        Entree input2 = new Entree("Input2");

        // Create gates
        PorteEt gateA = new PorteEt("GateA", input0, input1); // AND gate (a)
        PorteOu gateB = new PorteOu("GateB", input1, input2); // OR gate (b)
        Inverser gateF = new Inverser("GateF", input2);       // NOT gate (f)

        // Create circuit and add outputs
        Circuit circuit = new Circuit();
        circuit.addSortie(gateA);
        circuit.addSortie(gateB);
        circuit.addSortie(gateF);
        //circuit.addSortie(input2); // Output directly from input2 (throws error)

        // Display circuit
        System.out.println(circuit);

        // Retrieve all inputs for the circuit
        Set<Entree> allInputs = circuit.getEntrees();
        System.out.println("Inputs of the circuit:");
        for (Entree input : allInputs) {
            System.out.println(input.getName());
        }

        Map<Entree,Boolean> env = new HashMap<Entree,Boolean>();
        env.put(input0, false);
        env.put(input1, false);
        env.put(input2, true);

        circuit.evaluer(env);

        // Check for cycles
        System.out.println("Circuit is acyclic: " + circuit.isAcyclic());
    }
}
