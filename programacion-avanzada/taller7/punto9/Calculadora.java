public class Calculadora{
    private double x;
    private double y;
    private double res;
    public Calculadora(double xCalc, double yCalc){
        this.x = xCalc;
        this.y = yCalc;
    }
    public Calculadora(){
        x = 0;
        y = 0;
    }
    public void setX(double xCalc){
        x = xCalc;
    }
    public void setY(double yCalc){
        y = yCalc;
    }
    public double Suma(double a, double b){
        x=a;
        y=b;
        res = x+y;
        System.out.println(x + " + " + y + " = " + res);
        return x+y;
    }
    public double Suma(){
        res=x+y;
        System.out.println(x + " + " + y + " = " + res);
        return x+y;
    }
    public double Resta(double a, double b){
        x=a;
        y=b;
        res = x-y;
        System.out.println(x + " - " + y + " = " + res);
        return x-y;
    }
    public double Resta(){
        res = x-y;
        System.out.println(x + " - " + y + " = " + res);
        return x-y;
    }
    public double Multiplicar(double a, double b){
        x=a;
        y=b;
        res=x*b;
        System.out.println(x + " * " + y + " = " + res);
        return x*y;
    }
    public double Multiplicar(){
        res=x*y;
        System.out.println(x + " * " + y + " = " + res);
        return x*y;
    }
    public double Dividir(double a, double b){
        x=a;
        y=b;
        if(y==0){
            System.out.println("No se puede dividir entre 0");
            return 1;
        }
        else{
            res = x/y;
            System.out.println(x + " / " + y + " = " + res);
            return x/y;
        }
    }
    public double Dividir(){
        if(y==0){
            System.out.println("No se puede dividir entre 0");
            return 1;
        }
        else{
            res=x/y;
            System.out.println(x + " / " + y + " = " + res);
            return x/y;
        }
    }
}
