import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner myObj = new Scanner(System.in);
        System.out.println("Ingrese el nombre del perro: ");
        String nombre = myObj.nextLine();
        System.out.println("Ingrese la raza del perro");
        String raza = myObj.nextLine();
        Perro per = new Perro(nombre, raza);
        System.out.println("Ingrese la hora en que el  perro tomó agua");
        int hora = myObj.nextInt();
        per.SetTomoAgua(hora);
        per.GetTomoAgua();
    }
}
