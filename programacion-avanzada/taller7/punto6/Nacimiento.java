import java.util.Date;
import java.util.Calendar;

public class Nacimiento{
    Date date = new Date();
    Calendar fecha = Calendar.getInstance();
    private int anioNac;
    private int mesNac;
    private int diaNac;
    private int anioHoy = fecha.get(Calendar.YEAR);
    private int mesHoy = fecha.get(Calendar.MONTH);
    private int diaHoy = fecha.get(Calendar.DAY_OF_MONTH);
    private int anios;
    private int meses;
    private int dias;
    public Nacimiento(int an, int me, int di){
        this.anioNac = an;
        this.mesNac = me;
        this.diaNac = di;
    }
    public void calcEdad(){
        if(anioNac > anioHoy){
            System.out.println("Ingrese un año menor a el de hoy\n");
        }
        else{
            if(mesHoy > mesNac){
                anios = anioHoy - anioNac;
                if(diaHoy >= diaNac){
                    meses = mesHoy - mesNac + 1;
                    if(diaHoy==diaNac){
                        dias=0;
                    }
                    else{
                        dias = diaHoy - diaNac;
                    }
                }
                else{
                    meses = mesHoy - mesNac;
                    dias = (30-diaNac)+diaHoy;
                }
            }
            else if(mesHoy==mesNac){
                if(diaHoy >= diaNac){
                    anios = anioHoy - anioNac;
                    meses = 0;
                    if(diaHoy == diaNac){
                        dias = 0;
                    }
                    else{
                        dias = diaHoy - diaNac;
                    }
                }
                else{
                    anios = anioHoy - anioNac - 1;
                    meses = 11;
                    dias = (30-diaNac) + diaHoy;
                }
            }
            else{
                anioNac = anioHoy - anioNac - 1;
                if(diaHoy >= diaNac){
                    meses = 12 - (mesNac - mesHoy);
                    if(diaHoy==diaNac){
                        dias = 0;
                    }
                    else{
                        dias = diaHoy - diaNac;
                    }
                }
                else{
                    meses = 12 - (mesNac - mesHoy - 1);
                    dias = (30-diaNac) + diaHoy;
                }
            }
            System.out.println(anios + " años " + meses + " meses " + dias + " dias\n");
        }
    }
}
