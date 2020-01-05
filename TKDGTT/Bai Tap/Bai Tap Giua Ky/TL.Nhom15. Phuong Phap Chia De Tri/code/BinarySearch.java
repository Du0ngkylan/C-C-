
//Divide and Conquer: BinarySearch
import java.util.*;
public class BinarySearch {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int arr[]=new int[20];
      Random rd = new Random();
      System.out.println("In Mang:");
      for(int i=0;i<20;i++){
      	arr[i]=rd.nextInt(100);
      	System.out.print(arr[i]+"|");
      }
      System.out.println("\nDo dai: "+arr.length);
      System.out.println("Sap xep mang:");
      sort(arr);
      for(int i=0;i<20;i++){
      	System.out.print(arr[i]+"|");
      }
      Scanner sc= new Scanner(System.in);
      System.out.println("\nNhap phan tu can tim kiem: ");
      int key= sc.nextInt();
      binarysearch(arr,key,0,arr.length-1);
	}
	private static void binarysearch(int[] arr,int key,int left, int right) {
		// TODO Auto-generated method stub
		int mid;
		if(left==right){
			if(key==arr[left]){
				System.out.println("Vi tri arr["+left+"]="+key);
			}
		}
		else{
			mid=(left+right)/2;
			if(key==arr[mid]){
				System.out.println("Vi tri arr["+mid+"]="+key);
			}
			else{
				if(key<arr[mid]){
					binarysearch(arr,key,left,mid-1);
				}
				else{
					binarysearch(arr,key,mid+1,right);
				}
			}
		}
	}


	private static void sort(int[] arr) {
		// TODO Auto-generated method stub
		int i; int j; int temp;
		for(i=0; i<arr.length-1;i++){
			for(j=0;j<arr.length-1-i;j++){
				if(arr[j]>arr[j+1]){
					temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
				}
			}
		}
	}

	
}
