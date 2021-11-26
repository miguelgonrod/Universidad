import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner myObj = new Scanner(System.in);
        System.out.println("Ingrese el nombre del perro: ");
        String nombre = myObj.nextLine();
        System.out.println("Ingrese la raza del perro: ");
        String raza = myObj.nextLine();
        Perro per = new Perro(nombre, raza);
        System.out.println("Ingrese la hora en que el  perro tomó agua (Formato 24 horas): ");
        int hora = myObj.nextInt();
        myObj.skip("\n");
        while(hora < 0 || hora > 24){
            System.out.println("Ingrese una hora valida: ");
            hora = myObj.nextInt();
            myObj.skip("\n");
        }
        System.out.println("Ingrese el nombre del paseador de perros: ");
        String nombrePaseador = myObj.nextLine();
        PaseadorPerro pas = new PaseadorPerro(nombrePaseador);
        per.SetTomoAgua(hora);
        if(pas.Pasear(per)){
            System.out.println("Toca sacar el perro a pasear y tomar agua\n");
        }
        else{
            System.out.println("No toca sacar el perro a pasear aun\n");
        }
    }
}
