import java.util.*;

public class Env {
    private Map<String,double> Dict;
    public Env(){
        this.Dict=new TreeMap<>();
    }
    public void associer(String nom, double valeur){
        Dict.put(nom,valeur);
    }
    public double obtenir(String nom){
        return this.Dict.get(nom);
    }
    public String toString(){
        return this.Dict.toString();
    }
}