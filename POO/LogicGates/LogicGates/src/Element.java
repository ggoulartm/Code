import java.util.HashSet;
import java.util.Set;
import java.util.Map;

// Abstract class representing an Element
abstract class Element {
    private String name;
    private Set<Entree> entrees;
    private boolean visited = false;
    public Element(String name) {
        if (name == null) {
            throw new IllegalArgumentException("Name cannot be null");
        }
        entrees = new HashSet<>();
        this.name = name;
    }

    public Boolean hasCycle(){
        if(this.visited){
            return true;
        }
        this.visited = true;
        for(Entree e : entrees){
            if(e.hasCycle()) return true;
        }
        this.visited = false;
        return false;
    }

    public String getName() {
        return name;
    }

    public Set<Entree> getEntrees() {
        return entrees;
    }

    protected void addSource(Entree e){
        entrees.add(e);
    }

    protected void addAllSources(Set<Entree> entrees){
        this.entrees.addAll(entrees);
    }

    abstract public Boolean evaluer(Map<Entree, Boolean> env);

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
        Set<Entree> entrees = source.getEntrees();
        this.addAllSources(entrees);
    }

    public Element getSource() {
        return source;
    }

    public Boolean evaluer(Map<Entree, Boolean> env) {
        return !source.evaluer(env);
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
        Set<Entree> Entrees = source1.getEntrees();
        this.addAllSources(Entrees);
        this.source2 = source2;
        Entrees = source2.getEntrees();
        this.addAllSources(Entrees);
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

    public Boolean evaluer(Map<Entree, Boolean> env) {
        Boolean result = true;
        for(Entree e: getSource1().getEntrees()){
            result = result && e.isIn(env);
        }
        for(Entree e: getSource2().getEntrees()){
            result = result && e.isIn(env);
        }
        return result;
    }
}

// Class for the OR gate
class PorteOu extends PorteBinaire {
    public PorteOu(String name, Element source1, Element source2) {
        super(name, source1, source2);
    }

    public Boolean evaluer(Map<Entree, Boolean> env) {
        Boolean result = false;
        for(Entree e: getSource1().getEntrees()){
            result = result || e.isIn(env);
        }
        for(Entree e: getSource2().getEntrees()){
            result = result || e.isIn(env);
        }
        return result;
    }
}

// Class for simple inputs
class Entree extends Element {
    public Entree(String name) {
        super(name);
    }
    public Set<Entree> getEntrees() {
        Set<Entree> Entrees = new HashSet<>();
        Entrees.add(this);
        return Entrees;
    }

    public Boolean evaluer(Map<Entree, Boolean> env) {
        for(Entree e : env.keySet()){
            if(this == e){
                return env.get(e);
            }
        }
        return false;
    }

    public Boolean isIn(Map<Entree, Boolean> env) {
        for(Entree e : env.keySet()){
            if(this == e){
                return env.get(e);
            }
        }
        return null;
    }
}

class Circuit {
    static int defaultint = 0;
    static String DefaultName = "Default";
    private String name;
    Set<Entree> entrees;
    Set<Element> sorties;

    public Circuit(){
        this.name = DefaultName + defaultint++;
        entrees = new HashSet<>();
        sorties = new HashSet<>();
    }

    public void addSortie(Element e){
        for(Entree el: e.getEntrees()){
            if(entrees.contains(el) && el.getClass() != Entree.class){
                throw new IllegalArgumentException("The same element cannot be twice in a circuit");
            }
        }
        sorties.add(e);
        Set<Entree> Entrees = e.getEntrees();
        this.entrees.addAll(Entrees);
    }

    public Set<Entree> getEntrees() {
        return entrees;
    }

    @Override
    public String toString(){
        return name;
    }

    public void evaluer(Map<Entree, Boolean> env) {
        for(Element s: sorties){
            System.out.println("Element: "+s+" Sortie: "+s.evaluer(env));
        }
    }

    public Boolean isAcyclic(){
        for(Entree e: this.entrees){
            if(e.hasCycle()) return false;
        }
        return true;
    }
}
