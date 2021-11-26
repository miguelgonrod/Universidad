import java.util.Date;
import java.util.Calendar;

public class Persona{
    Date date = new Date();
    private String nombre;
    private int anio;
    private int mes;
    private int dia;
    Calendar fecha = Calendar.getInstance();
    private int anioHoy = fecha.get(Calendar.YEAR);
    private int mesHoy = fecha.get(Calendar.MONTH);
    private int diaHoy = fecha.get(Calendar.DAY_OF_MONTH);
    public Persona(String nom, int an, int me, int di){
        this.nombre = nom;
        this.anio = an;
        this.mes = me;
        this.dia = di;
    }
    public void Imprimir(){
        if(anio> anioHoy){
            System.out.println("Ingrese un año menor a el de hoy\n");
        }
        else{
            if(mesHoy > mes){
                anio = anioHoy - anio;
                if(diaHoy >= dia){
                    mes = mesHoy - mes + 1;
                    if(diaHoy==dia){
                        dia=0;
                    }
                    else{
                        dia = diaHoy - dia;
                    }
                }
                else{
                    mes = mesHoy - mes;
                    dia = (30-dia)+diaHoy;
                }
            }
            else if(mesHoy==mes){
                if(diaHoy >= dia){
                    anio = anioHoy - anio;
                    mes = 0;
                    if(diaHoy == dia){
                        dia = 0;
                    }
                    else{
                        dia = diaHoy - dia;
                    }
                }
                else{
                    anio = anioHoy - anio - 1;
                    mes = 11;
                    dia = (30-dia) + diaHoy;
                }
            }
            else{
                anio = anioHoy - anio - 1;
                if(diaHoy >= dia){
                    mes = 12 - (mes - mesHoy);
                    if(diaHoy==dia){
                        dia = 0;
                    }
                    else{
                        dia = diaHoy - dia;
                    }
                }
                else{
                    mes = 12 - (mes - mesHoy - 1);
                    dia = (30-dia) + diaHoy;
                }
            }
            System.out.println("Nombre completo: " + nombre + "\n" + "Edad: " + anio + " años " + mes + " meses y " + dia + " dias\n");
        }
    }
}
