package Java;

public class recursive {
    public static void main(String[] args) {
        recursive r = new recursive();
        System.out.println(r.a(10000));
        System.out.println(nonRecursive(10000));
    }

    long a(long num){
        if(num == 1){
            return 1;
        }
        return num + a(num-1);
    }

    static long nonRecursive(int num) {
        long ans = 0;
        while (num > 0) {
            ans += num;
            num--;
        }
        return ans;
    }
}