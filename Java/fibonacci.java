package Java;

public class fibonacci {
    static int n;
    static long ans;
    static long bef;
    public fibonacci(int num){
        n = num;
        bef = 1;
        ans = 1;
        calc(n);
    }    

    private static void calc(int n) {
        int ptr = n;
        while (ptr > 2) {
            long temp = ans;
            ans = bef + ans;
            bef = temp;
            System.out.println(ans);
            ptr--;
        }
    }

    public static void main(String[] args) {
        new fibonacci(100);
    }
}
