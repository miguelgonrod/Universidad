import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner myObj = new Scanner(System.in);
        System.out.println("Ingrese el tipo de figura 1)circulo 2)triangulo 3)rectangulo: ");
        int tipo = myObj.nextInt();
        if(tipo == 1){
            System.out.println("Ingrese el radio de la figura: ");
            double radio = myObj.nextDouble();
            Figura fig = new Figura(radio, tipo);
            fig.Area();
            fig.Perimetro();
        }
        else{
            System.out.println("Ingrese el ancho de la figura: ");
            double ancho = myObj.nextDouble();
            System.out.println("Ingrese la altura de la figura: ");
            double alto = myObj.nextDouble();
            Figura fig = new Figura(ancho, alto, tipo);
            fig.Area();
            fig.Perimetro();
        }
    }
}
