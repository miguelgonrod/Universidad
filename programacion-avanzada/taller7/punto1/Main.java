import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner myObj = new Scanner(System.in);
        System.out.println("Ingrese el ancho de la figura: ");
        double ancho = myObj.nextDouble();
        System.out.println("Ingrese la altura de la figura: ");
        double alto = myObj.nextDouble();
        System.out.println("Ingrese el tipo de figura 1)triangulo 2)rectangulo: ");
        int tipo = myObj.nextInt();
        Figura fig = new Figura(ancho,alto);
        fig.Area(tipo);
    }
}
