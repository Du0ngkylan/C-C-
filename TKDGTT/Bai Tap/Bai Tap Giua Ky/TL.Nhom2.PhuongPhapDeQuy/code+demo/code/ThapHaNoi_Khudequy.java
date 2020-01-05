package myTestStack;

import java.util.HashMap;
import java.util.Stack;

public class TestHaNoiTower_Interative {
	public static void main(String [] args)
	{
		HanoiTower_Iterative(3, 'A', 'B', 'C');
	}
	public static void HanoiTower_Iterative(int n, char x, char y, char z)
	{
		Stack<Quad> stack = new Stack<Quad>();
		Quad quad = new Quad(n, x, y, z);
		stack.push(quad);
		do {
			Quad temp = stack.pop();
			char A = temp.a;
			char B = temp.b;
			char C = temp.c;
			if (temp.n == 1)
				System.out.println("Chuyen " + temp.a + " --> " + temp.c);
			else
			{
				int N = temp.n;
				temp = new Quad(N-1, B, A, C);	// dua vao stack truoc nen day la buoc cuoi
				stack.push(temp);
				temp = new Quad(1, A, B, C);
				stack.push(temp);
				temp = new Quad(N-1, A, C, B);
				stack.push(temp);
			}
	} while (!stack.isEmpty());
			
	}
}
class Quad{
	public int n;
	public char a,b,c;
	public Quad(int n, char a, char b, char c){
		this.n = n;
		this.a = a;
		this.b = b;
		this.c = c;
	}
}