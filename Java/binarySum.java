package Java;

public class binarySum {
    static int[] a;
    public static void main(String[] args) {
        a = new int[]{1,2,3,4,5,6};
        long ans = binarySum_(a);
        System.out.println(ans);
    }

    public static long binarySum_(int[] a) {
        return binarySum_(a, 0, a.length-1);
    }

    public static long binarySum_(int[] a, int start, int end) {
        if (start < end) {
            int mid = (start + end) / 2;
            return binarySum_(a, start, mid) + binarySum_(a, mid+1, end);
        }
        return a[start];
    }
    
}
