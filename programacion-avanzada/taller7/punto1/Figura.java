public class Figura{
    private double ancho;
    private double alto;

    public Figura(double an, double alt){
        this.ancho = an;
        this.alto = alt;
    }
    public double Area(int tipofigura){
        if(tipofigura==1){
            System.out.println("El area del triangulo es: " + (ancho*alto)/2);
            return ((ancho*alto)/2);
        }
        else if(tipofigura==2){
            System.out.println("El area del rectangulo es: " + (ancho*alto));
            return (ancho*alto);
        }
        else{
            System.out.println("Numero invalido, ingrese uno entre 1 y 2");
            return 1;
        }
    }
}
