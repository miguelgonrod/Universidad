import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner myObj = new Scanner(System.in);
        int anio;
        int mes;
        int dia;
        System.out.println("Ingrese su nombre completo: ");
        String nombre = myObj.nextLine();
        System.out.println("Ingrese su año de nacimiento: ");
        anio = myObj.nextInt();
        System.out.println("Ingrese su mes de nacimiento: ");
        mes = myObj.nextInt();
        System.out.println("Ingrese su dia de nacimiento: ");
        dia = myObj.nextInt();
        Persona per = new Persona(nombre, anio, mes, dia);
        per.Imprimir();
    }
}
