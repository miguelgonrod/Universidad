import java.util.Calendar;

public class PaseadorPerro{
    Calendar calendario = Calendar.getInstance();
    private String nombrePaseador;
    private int horaPerro;
    private int horaAct = calendario.get(Calendar.HOUR_OF_DAY);
    public PaseadorPerro(String nom){
        this.nombrePaseador = nom;
    }
    public void setNom(String nombre){
        this.nombrePaseador = nombre;
    }
    public boolean Pasear(Perro ElPerro){
        horaPerro = ElPerro.GetTomoAgua();
        if(horaPerro>horaAct){
            return true;
        }
        else if(horaAct - horaPerro >=4){
            return true;
        }
        else{
            return false;
        }
    }
}
