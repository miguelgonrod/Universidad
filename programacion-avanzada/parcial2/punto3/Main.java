import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner myObj = new Scanner(System.in);
        Triangulo tri = new Triangulo();
        int[] arreglo=new int[5];
        for(int i = 0; i < 5; i++){
            System.out.println("Ingrese el valor de la posicion " + i + ": ");
            arreglo[i]=myObj.nextInt();
        }
        System.out.println("El triangulo de suma es: \n");
        tri.Calcular(arreglo, 5);
    }
}
