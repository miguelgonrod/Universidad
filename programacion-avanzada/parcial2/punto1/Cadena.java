public class Cadena{
    public static void operar(String texto){
        int carNoRepetido=0;
        int fin = 0;
        int prev=0;
        System.out.println("Cadena: " + texto + "\n");
        for(int i = 0; i < texto.length();i++){
            for(int j = 0; j < texto.length();j++){
                if(texto.charAt(j)==texto.charAt(i) && j!=i){
                    if(j > prev){
                        prev = j;
                    }
                    break;
                }
                else if(j <= i){
                    carNoRepetido = i;
                }
                else if(j==texto.length()-1 && texto.charAt(j)!=texto.charAt(i)){
                    fin=1;
                }
                if(j>=prev){
                    System.out.println("Lectura: " + texto.charAt(j));
                    System.out.println("El primer caracter que no se repite hasta ahora es: " + texto.charAt(carNoRepetido));
                }
            }
            if(fin==1){
                break;
            }
        }
        if(carNoRepetido>=0){
            System.out.println("Se confirma que el primer caracter que no se repite es: " + texto.charAt(carNoRepetido));
        }
        else{
            System.out.println("Todos se repiten");
        }
    }
}
