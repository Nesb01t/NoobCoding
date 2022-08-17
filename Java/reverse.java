package Java;

public class reverse {
    public static int a[];

    public static void main(String[] args) {
        a = new int[]{1, 2, 3, 4, 5};
        reverseArr(a);
        printArr(a);
    }

    public static int[] reverseArr(int[] a) {
        return reverseArr(a, a.length);
    }
    public static int[] reverseArr(int[] a, int length) {
        return reverseArr(a, 0, length-1);
    }
    public static int[] reverseArr(int[] a, int start, int end) {
        if (start < end)
        {
            // new array
            int tmp[] = a;

            // swap
            int num = tmp[start];
            tmp[start] = tmp[end];
            tmp[end] = num;

            // return
            return reverseArr(tmp, start+1, end-1);
        }
        else
        {
            return a;
        }
    }
    
    public static void printArr(int[] a) {
        for (int i = 0; i < a.length; i++)
        {
            System.out.print(a[i]+" ");
        }
        System.out.println();
    }
}
