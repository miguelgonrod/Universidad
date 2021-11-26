public class Perro{
    private String nombre;
    private String raza;
    private int hora;
    public Perro(String nombre, String raza){
        this.nombre = nombre;
        this.raza = raza;
    }
    public void setNom(String nom){
        this.nombre = nom;
    }
    public void setRaza(String raza){
        this.raza = raza;
    }
    public void SetTomoAgua(int hora){
        this.hora = hora;
    }
    public int GetTomoAgua(){
        return hora;
    }
}
