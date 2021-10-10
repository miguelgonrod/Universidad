public class Figura{
    private double ancho;
    private double alto;
    private double radio;
    private int tipofigura;

    public Figura(double an, double alt, int tip){
        this.ancho = an;
        this.alto = alt;
        this.tipofigura = tip;
    }
    public Figura(double rad, int tip){
        this.radio = rad;
        this.tipofigura = tip;
    }
    public double Area(){
        if(tipofigura==1){
            System.out.println("El area del circulo es: " + "π*" + radio + "² = " + (radio*radio*Math.PI));
            return (radio*radio*Math.PI);
        }
        else if(tipofigura==2){
            System.out.println("El area del triangulo es: (" + ancho + "*" + alto + ")/2" + " = " + (ancho*alto)/2);
            return ((ancho*alto)/2);
        }
        else if(tipofigura==3){
            System.out.println("El area del rectangulo es: " + ancho + "*" + alto + " = " + (ancho*alto));
            return (ancho*alto);
        }
        else{
            System.out.println("Numero invalido, ingrese uno entre 1 y 3");
            return 1;
        }
    }
    public double Perimetro(){
        double hipotenusa = Math.sqrt((ancho*ancho)+(alto*alto));
        if(tipofigura==1){
            System.out.println("El perimetro del circulo es: 2*π*" + radio + " = " + (2*Math.PI*radio));
            return (2*Math.PI*radio);
        }
        else if(tipofigura==2){
            System.out.println("El perimetro del triangulo (triangulo rectangulo) es: " + ancho + "+" + alto + "+" + hipotenusa + " = " + (ancho+alto+hipotenusa));
            return (ancho+alto+hipotenusa);
        }
        else if(tipofigura==3){
            System.out.println("El perimetro de un rectangulo es: 2*" + ancho + "+2*" + alto + " = " + (2*ancho + 2*alto));
            return (2*ancho + 2*alto);
        }
        else{
            System.out.println("Numero invalido, ingrese uno entre 1 y 3");
            return 1;
        }
    }
}
