import java.time.LocalDate;
import java.time.ZoneId;
import java.util.Date;

public class Persona{
    Date date = new Date();
    ZoneId timeZone = ZoneId.systemDefault();
    LocalDate getLocalDate = date.toInstant().atZone(timeZone).toLocalDate();
    private String nombre;
    private int anio;
    private int anioHoy = getLocalDate.getYear();
    public Persona(String nom, int an){
        this.nombre = nom;
        this.anio = an;
    }
    public void Imprimir(){
        if(anio> anioHoy){
            System.out.println("Ingrese un año menor a el de hoy\n");
        }
        else{
            anio = anioHoy - anio;
            System.out.println("Nombre completo: " + nombre + "\n" + "Edad: " + anio);
        }
    }
}
