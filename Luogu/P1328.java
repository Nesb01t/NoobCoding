package Luogu;

import java.util.Scanner;

public class P1328 {
    public static void main(String[] args) {
        int a = 0, b = 0; // a为甲, 自己的分数
        int rank[][] = {
            {0, -1, 1, 1, -1},
            {1, 0, -1, 1, -1},
            {-1, 1, 0, -1, 1},
            {-1, -1, 1, 0, 1},
            {1, 1, -1, -1, 0}
        };

        try (Scanner in = new Scanner(System.in)) {
            int time = in.nextInt();
            int a_per = in.nextInt();
            int a_ans[] = new int[a_per];
            int b_per = in.nextInt();
            int b_ans[] = new int[b_per];

            for (int i = 0; i < a_per; i++) {
                a_ans[i] = in.nextInt();
            }
            for (int i = 0; i < b_per; i++) {
                b_ans[i] = in.nextInt();
            }

            int a_last = 0, b_last = 0;
            for (int i = 0; i < time; i++) {
                if(rank[a_ans[a_last]][b_ans[b_last]]==1){
                    a++;
                }else if(rank[a_ans[a_last]][b_ans[b_last]]==-1){
                    b++;
                }

                a_last++;b_last++;
                if(a_last == a_per){a_last = 0;}
                if(b_last == b_per){b_last = 0;}
            }
        }
        System.out.println(a+" "+b);
    }
}
