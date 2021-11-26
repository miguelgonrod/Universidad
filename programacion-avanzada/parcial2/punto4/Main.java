import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner myObj = new Scanner(System.in);
        String nombre = "firulais";
        String raza = "huskee";
        String nomPas = "jose";
        PaseadorPerro pas = new PaseadorPerro(nomPas);
        Perro per = new Perro(nombre,raza);
        int crePer=0, crePas=0, opcion=0, hora=0;
        while(opcion!=5){
            System.out.println("Ingrese una opcion 1)instancie un perro 2)instancie un paseador 3)perro toma agua 4) se debe pasear el perro? 5)salir: ");
            opcion = myObj.nextInt();
            myObj.skip("\n");
            if(opcion==1){
                System.out.println("Ingrese el nombre del perro: ");
                nombre = myObj.nextLine();
                per.setNom(nombre);
                System.out.println("Ingrese la raza del perro: ");
                raza = myObj.nextLine();
                per.setRaza(raza);
                crePer=1;
            }
            else if(opcion==2){
                System.out.println("Ingrese el nombre del paseador: ");
                nomPas = myObj.nextLine();
                pas.setNom(nomPas);
                crePas=1;
            }
            else if(opcion==3){
                if(crePer!=1){
                    throw new RuntimeException("Se debe instanciar un perro primero");
                }
                else{
                    System.out.println("Ingrese la hora a la que el perro tomó agua (solo la hora en formato 24h): ");
                    hora = myObj.nextInt();
                    while(hora<0){
                        System.out.println("Ingrese una hora mayor a 0");
                        hora = myObj.nextInt();
                        myObj.skip("\n");
                    }
                    per.SetTomoAgua(hora);
                }
            }
            else if(opcion==4){
                if(crePer!=1){
                    throw new RuntimeException("Se debe instanciar un perro primero");
                }
                else if(crePas!=1){
                    throw new RuntimeException("Se debe instanciar un paseador primero");
                }
                else if(hora==0){
                    throw new RuntimeException("se debe definir la ultima hora en la cual el perro tomó agua");
                }
                else{
                    if(pas.Pasear(per)){
                        System.out.println("Toca sacar el perro");
                    }
                    else{
                        System.out.println("No toca sacar el perro aun");
                    }
                }
            }
        }
    }
}
