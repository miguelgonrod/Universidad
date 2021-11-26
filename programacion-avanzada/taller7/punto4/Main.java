import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner myObj = new Scanner(System.in);
        int anio;
        System.out.println("Ingrese su nombre completo: ");
        String nombre = myObj.nextLine();
        System.out.println("Ingrese su año de nacimiento: ");
        anio = myObj.nextInt();
        Persona per = new Persona(nombre, anio);
        per.Imprimir();
    }
}
