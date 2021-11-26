public class Triangulo{
    public void Calcular(int arr[], int num){
        int[] nuarreglo=new int[num-1];
        for(int i = 0; i < num-1; i++){
            nuarreglo[i] = arr[i]+arr[i+1];
            System.out.println(arr[i] + " + " + arr[i+1] + " = " + nuarreglo[i]);
        }
        System.out.println("\n");
        if(num>1){
            Calcular(nuarreglo,num-1);
        }
        else if(num==1){
            System.out.println(arr[0]);
        }
    }
}
