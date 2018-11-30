# Projet

TP Note en POO 
- Log4J
- JUnit

# Compte rendu

**Question 15** 

```java
public class Groupe {
    private List<Integer> liste = new ArrayList<Integer>();
    private Integer repere;

    public Groupe(Integer r) {
        repere = r;
    }

    public Groupe(String r) {
        repere = Integer.valueOf(r);
    }

    public void setMembre(Integer m) {
        liste.add(m);
    }

    public void setMembre(String m) {
        liste.add(Integer.valueOf(m));
    }

    public void afficher() {
        for (Integer membre : liste) {
            if (this.isCorrect(membre)) {
                System.out.println(membre);
            }
        }
    }

    private boolean isCorrect(Integer membre) {
        return ((membre != null) && membre.compareTo(repere) > 0);
    }
}
```
```java
public class Groupe<T> {
    private List<T> liste = new ArrayList<T>();
    private T repere;

    public Groupe(T r) {
        repere = r;
    }

    public void setMembre(T m) {
        liste.add(m);
    }

    public void afficher() {
        for (T membre : liste) {
            if (this.isCorrect(membre)) {
                System.out.println(membre);
            }
        }
    }

    private boolean isCorrect(T membre) {
        return ((membre != null) && membre.compareTo(repere) > 0);
    }
}
```

