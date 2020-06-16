package baitap3;
// Recursive: Decimal to Binary,Prime Number, Tower of Ha Noi
import java.util.*;
public class Bai2Tester {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.err.println("Ket qua co the khong chinh xac o bai toan FIBONACCI neu nhap so thu tu > 46. Do bi gioi han ve kieu so.");
		Scanner sc= new Scanner(System.in);
		System.out.print("Nhap so: ");
		int songuyen= sc.nextInt();
		int i=2;
		int fib1=1;
		int fib2=0;
		int stt=1;
		System.out.print("\nSo nguyen "+songuyen+" chuyen sang he nhi phan la: " );
		timnhiphan(songuyen);
		System.out.print("\nSo nguyen "+songuyen+" duoc phan tich thanh cac thua so nguyen to: ");
		thuasongto(songuyen,i);
		System.out.print("\nSo Fibonacci thu "+songuyen+" la: ");
		fibonacci(songuyen,fib1,fib2,stt);
		System.out.println("\nBAI TOAN THAP HA NOI(Tower of Ha Noi)");
		System.out.println("Nhap so dia muon chuyen: ");
		int sodia= sc.nextInt();
		char cotnguon = 'A';
		char cotgiua = 'B';
		char cotdich = 'C';
		System.out.println("Cac buoc can chuyen la:");
		chuyenthap(sodia,cotnguon,cotdich,cotgiua);
	}

	private static void chuyenthap(int sodia, char cotnguon, char cotdich, char cotgiua) {
		// TODO Auto-generated method stub
		if(sodia>0){
			chuyenthap(sodia-1,cotnguon,cotgiua,cotdich);
			System.out.println(cotnguon+"-->"+cotdich);
			chuyenthap(sodia-1,cotgiua,cotdich,cotnguon);
		}
		
	}

	private static void fibonacci(int songuyen, int fib1, int fib2, int stt) {
		// TODO Auto-generated method stub
		int fib = 0;
		if(songuyen==0){
			fib=0;
		}
		if(songuyen==1){
			fib=1;
		}
		fib=fib1+fib2;
		fib2=fib1;
		fib1=fib;
		stt=stt+1;
		if(songuyen>=2 && stt<songuyen){
			fibonacci(songuyen,fib1,fib2,stt);
		}
		else{
			System.out.print(fib);
		}
	}

	private static void thuasongto(int songuyen, int i) {
		// TODO Auto-generated method stub
		int k= songuyen/i;
		int j= songuyen%i;
		if(songuyen<i){
			System.out.print("");
		}
		else{
			if(j==0){
				System.out.print(i+".");
				thuasongto(k,i);
			}
		    if(j!=0){
		    	i=i+1;
		    	thuasongto(songuyen,i);
		    }
		}
	}

	private static void timnhiphan(int songuyen) {
		// TODO Auto-generated method stub
		String nhiphan= new String();
		int k=songuyen/2;
		int j=songuyen%2;
		if(k==0){
			nhiphan = "1";
		}
		else{
			if(j==0) nhiphan = nhiphan + "0";
			if(j==1) nhiphan = nhiphan + "1";
			timnhiphan(k);
		}
		System.out.print(nhiphan);
	}
	

}
