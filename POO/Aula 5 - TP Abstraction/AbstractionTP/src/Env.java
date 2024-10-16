import java.util.*;

public class Env {
    private Map<Variable,Constante> Dict;
    public Env(){
        this.Dict=new TreeMap<>();
    }
    public void associer(Variable nom, Constante valeur){
        Dict.put(nom,valeur);
    }
    public Constante obtenir(String nom){
        return this.Dict.get(new Variable(nom));
    }
    public String toString(){
        return this.Dict.toString();
    }
}