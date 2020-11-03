import java.util.Scanner;

public class Termometer{
	public void Fahrenheit(double suhu){
		suhu = (suhu * 9 /5)+32;
		System.out.println("Hasil Konversi Celcius ke Fahrenheit =  " + suhu + " derajat Fahrenheit");
    }
	public void Celcius(double suhu){
	suhu = (suhu -32) * 5/9;
        System.out.println("Hasil Konversi Fahrenheit ke Celcius =  " + suhu + " derajat Celcius");
	}
}

public class suhu{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        System.out.println("Pilihlah tipe konversi: ");
		System.out.print("1.Celcius ke Fahrenheit\n2.Fahrenheit ke Celcius");
        Double pilihan=input.nextDouble();
        System.out.print("Masukkan suhu: ");
        Double suhu=input.nextDouble();
		
		Termometer asd = new Termometer();
		if(pilihan==1) asd.Fahrenheit(suhu);
		else asd.Celcius(suhu);
    }
}