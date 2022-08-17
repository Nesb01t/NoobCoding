package Java;

import java.util.Scanner;

public class hello{
    static class test {
        public String name;
        public int flag;
    }
    public static void main(String args[]){
        try (Scanner in = new Scanner(System.in)) {
            test a[] = new test[2];
            a[1].flag = in.nextInt();
            a[2].flag = in.nextInt();

            System.out.println(a[1].flag + a[2].flag);
        }
    }
}