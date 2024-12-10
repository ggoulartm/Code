// Abstract class representing an Element
abstract class Element {
    private String name;

    public Element(String name) {
        if (name == null) {
            throw new IllegalArgumentException("Name cannot be null");
        }
        this.name = name;
    }

    public String getName() {
        return name;
    }

    @Override
    public String toString() {
        return name;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Element element = (Element) obj;
        return name.equals(element.name);
    }

    @Override
    public int hashCode() {
        return name.hashCode();
    }
}

// Class for the Inverser (NOT gate)
class Inverser extends Element {
    private Element source;

    public Inverser(String name, Element source) {
        super(name);
        if (source == null) {
            throw new IllegalArgumentException("Source cannot be null");
        }
        this.source = source;
    }

    public Element getSource() {
        return source;
    }
}

// Abstract class for binary gates
abstract class PorteBinaire extends Element {
    private Element source1;
    private Element source2;

    public PorteBinaire(String name, Element source1, Element source2) {
        super(name);
        if (source1 == null || source2 == null) {
            throw new IllegalArgumentException("Sources cannot be null");
        }
        this.source1 = source1;
        this.source2 = source2;
    }

    public Element getSource1() {
        return source1;
    }

    public Element getSource2() {
        return source2;
    }
}

// Class for the AND gate
class PorteEt extends PorteBinaire {
    public PorteEt(String name, Element source1, Element source2) {
        super(name, source1, source2);
    }
}

// Class for the OR gate
class PorteOu extends PorteBinaire {
    public PorteOu(String name, Element source1, Element source2) {
        super(name, source1, source2);
    }
}

// Class for simple inputs
class Entree extends Element {
    public Entree(String name) {
        super(name);
    }
}
