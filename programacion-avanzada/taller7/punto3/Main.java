import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner myObj = new Scanner(System.in);
        double radio = 0, ancho = 0, alto = 0;
        int tipo;
        System.out.println("Ingrese el tipo de figura 1)circulo 2)triangulo 3)rectangulo: ");
        tipo = myObj.nextInt();
        if(tipo == 1){
            System.out.println("Ingrese el radio de la figura: ");
            radio = myObj.nextDouble();
            Figura fig = new Figura(radio, tipo);
            fig.Area();
            fig.Perimetro();
        }
        else{
            System.out.println("Ingrese el ancho de la figura: ");
            ancho = myObj.nextDouble();
            System.out.println("Ingrese la altura de la figura: ");
            alto = myObj.nextDouble();
            Figura fig = new Figura(ancho, alto, tipo);
            fig.Area();
            fig.Perimetro();
        }
        System.out.println("Ingrese otro tipo de figura 1)circulo 2)triangulo 3)rectangulo: ");
        tipo = myObj.nextInt();
        Figura fig = new Figura(ancho, alto, tipo);
        fig.setFigura(tipo);
        if(tipo == 1){
            System.out.println("Ingrese el radio de la figura: ");
            radio = myObj.nextDouble();
            fig.setRadio(radio);
            fig.Area();
            fig.Perimetro();
        }
        else{
            System.out.println("Ingrese el ancho de la figura: ");
            ancho = myObj.nextDouble();
            System.out.println("Ingrese la altura de la figura: ");
            alto = myObj.nextDouble();
            fig.setAncho(ancho);
            fig.setAlto(alto);
            fig.Area();
            fig.Perimetro();
        }
    }
}
