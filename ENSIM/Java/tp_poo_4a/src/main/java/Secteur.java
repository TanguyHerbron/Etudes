import java.util.ArrayList;
import java.util.List;

public class Secteur {

    final public static int NB_MAX_VISITEURS = 15;

    private TypeAnimal typeAnimauxDansSecteurs;
    private List<Animal> animauxDansSecteur;

    public Secteur(TypeAnimal typeAnimal)
    {
        this.typeAnimauxDansSecteurs = typeAnimal;

        animauxDansSecteur = new ArrayList<Animal>();
    }

    public void ajouterAnimal(Animal animal)
    {
        animauxDansSecteur.add(animal);
    }

    public int getNombreAnimaux()
    {
        return animauxDansSecteur.size();
    }

    public TypeAnimal obtenirType()
    {
        return typeAnimauxDansSecteurs;
    }
}
