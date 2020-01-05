import java.util.*;

public class MaxMin {

    static int[] arr;
    int max, min;

    public MaxMin(int n) {
        arr = new int[n];
        Random rd = new Random();
        for (int i = 0; i < n; i++) {
        	arr[i]=rd.nextInt(100);
        }
    }

    public int getMax() {
        return max;
    }

    public int getMin() {
        return min;
    }

    public void print() {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + "|");
        }
        System.out.println();
    }
    
    private void dacMaxMini() {
        dacMaxMin(arr,0, arr.length - 1);
		
	}
    public void dacMaxMin(int[] array, int left, int right) {
        int max1, min1, mid, max2, min2;
        if(right-left<=1){
        	if(array[left]<array[right]){
        		max = array[right];
                min = array[left];
            }
        	else {
                max = array[left];
                min = array[right];
            }
        }
        else{
        	mid=(left+right)/2;
        	dacMaxMin(array,left,mid);
        	max1=max;
        	min1=min;
        	dacMaxMin(array,mid+1,right);
        	max2=max;
        	min2=min;
        	if (max2 < max1) {
                max = max1;
            }
            if (min2 > min1) {
                min = min1;
            }
        }
        
    }

    public static void main(String[] a) {
        MaxMin m = new MaxMin(15);
        System.out.println("In Mang:");
        m.print();
        m.dacMaxMini();
        System.out.println("Gia tri lon nhat trong mang : " + m.getMax());
        System.out.println("Gia tri nho nhat trong mang : " + m.getMin());
    }

	

}
