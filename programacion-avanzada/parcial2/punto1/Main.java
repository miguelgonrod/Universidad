import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner myObj = new Scanner(System.in);
        String cadena;
        System.out.println("Ingrese la cadena a operar: ");
        cadena = myObj.nextLine();
        Cadena.operar(cadena);
    }
}
