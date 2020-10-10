import java.util.Scanner;

public class FPB {

    private static int fpb(int a, int b) {
        return b==0? a : fpb(b,a%b);
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Program mencari FPB 2 bilangan");
        System.out.print("Masukkan angka pertama : ");
        int a = scan.nextInt();
        System.out.print("Masukkan angka kedua : ");
        int b = scan.nextInt();
        System.out.println("FPB "+a+" dan "+b+" = " + fpb(a,b));
    }

}
