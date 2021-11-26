import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner myObj = new Scanner(System.in);
        Calculadora calc = new Calculadora();
        System.out.println("Desea modificar los datos? 1)si 2)no: ");
        int inicio = myObj.nextInt();
        while(inicio < 1 || inicio > 2){
            System.out.println("Ingrese un valor valido: ");
            inicio = myObj.nextInt();
        }
        if(inicio==1){
            System.out.println("Ingrese el primer y segundo valor separados por un espacio: ");
            double x = myObj.nextDouble();
            double y = myObj.nextDouble();
            calc.setX(x);
            calc.setY(y);
        }
        System.out.println("Desea 1)sumar 2)restar 3)multiplicar 4)dividir: ");
        int operacion = myObj.nextInt();
        while(operacion < 1 || operacion > 4){
            System.out.println("Ingrese un valor valido: ");
            inicio = myObj.nextInt();
        }
        if(operacion==1){
            System.out.println("Desea ingresar nuevos datos? 1)si 2)no: ");
            inicio = myObj.nextInt();
            while(inicio < 1 || inicio > 2){
                System.out.println("Ingrese un valor valido: ");
                inicio = myObj.nextInt();
            }
            if(inicio==1){
                System.out.println("Ingrese el primer y segundo valor separados por un espacio: ");
                double x = myObj.nextDouble();
                double y = myObj.nextDouble();
                calc.Suma(x,y);
            }
            else{
                calc.Suma();
            }
        }
        else if(operacion==2){
            System.out.println("Desea ingresar nuevos datos? 1)si 2)no: ");
            inicio = myObj.nextInt();
            while(inicio < 1 || inicio > 2){
                System.out.println("Ingrese un valor valido: ");
                inicio = myObj.nextInt();
            }
            if(inicio==1){
                System.out.println("Ingrese el primer y segundo valor separados por un espacio: ");
                double x = myObj.nextDouble();
                double y = myObj.nextDouble();
                calc.Resta(x,y);
            }
            else{
                calc.Resta();
            }
        }
        if(operacion==3){
            System.out.println("Desea ingresar nuevos datos? 1)si 2)no: ");
            inicio = myObj.nextInt();
            while(inicio < 1 || inicio > 2){
                System.out.println("Ingrese un valor valido: ");
                inicio = myObj.nextInt();
            }
            if(inicio==1){
                System.out.println("Ingrese el primer y segundo valor separados por un espacio: ");
                double x = myObj.nextDouble();
                double y = myObj.nextDouble();
                calc.Multiplicar(x,y);
            }
            else{
                calc.Multiplicar();
            }
        }
        if(operacion==4){
            System.out.println("Desea ingresar nuevos datos? 1)si 2)no: ");
            inicio = myObj.nextInt();
            while(inicio < 1 || inicio > 2){
                System.out.println("Ingrese un valor valido: ");
                inicio = myObj.nextInt();
            }
            if(inicio==1){
                System.out.println("Ingrese el primer y segundo valor separados por un espacio: ");
                double x = myObj.nextDouble();
                double y = myObj.nextDouble();
                calc.Dividir(x,y);
            }
            else{
                calc.Dividir();
            }
        }
    }
}
