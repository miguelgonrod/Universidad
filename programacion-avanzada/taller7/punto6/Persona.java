
public class Persona{
    private String nombre;
    private int anio;
    private int mes;
    private int dia;
    public Persona(String nom, int an, int me, int di){
        this.nombre = nom;
        this.anio = an;
        this.mes = me;
        this.dia = di;
    }
    public void Imprimir(){
        Nacimiento nac = new Nacimiento(anio, mes, dia);
        System.out.print("Nombre completo: " + nombre + "\n" + "Edad: ");
        nac.calcEdad();
    }
}
