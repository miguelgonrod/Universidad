public class Perro{
    private String nombre;
    private String raza;
    private int hora;
    public Perro(String nom, String ra){
        this.nombre = nom;
        this.raza = ra;
    }
    public void SetTomoAgua(int hor){
        hora = hor;
    }
    public void GetTomoAgua(){
        System.out.println("El perro " + nombre + " tomó agua a las " + hora);
    }
}
