package Luogu;

import java.util.Scanner;

public class P4924 {
    static int[][] spawn_rotate(int len){ // 生成矩阵
        int a[][] = new int[len][len];
        int last = 1;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                a[i][j] = last;
                last++;
            }
        }
        
        return a;
    }

    static int[][] rotate_(int a[][], int len, int z){ // 旋转矩阵, 带长度
        int newmat[][] = new int[len][len];
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                if(z==0){
                    newmat[i][j] = a[len-1-j][i];
                }else if(z==1){
                    newmat[i][j] = a[j][len-1-i];
                }
            }
        }
        return newmat;
    }

    static void printmat(int a[][], int len){ // 打印矩阵
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                System.out.print(a[i][j]+" ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            int len = in.nextInt();
            int a[][] = spawn_rotate(len);
            int time = in.nextInt();

            for (int i = 0; i < time; i++) {
                int x = in.nextInt();
                int y = in.nextInt();
                int r = in.nextInt();
                int z = in.nextInt();
                int tmp[][] = new int[2*r+1][2*r+1];

                for (int j = x-1-r; j <= x-1+r; j++) {
                    for (int j2 = y-1-r; j2 <= y-1+r; j2++) {
                        tmp[j-(x-1-r)][j2-(y-1-r)] = a[j][j2];
                    }
                }

                tmp = rotate_(tmp, 2*r+1, z);
                for (int j = x-1-r; j <= x-1+r; j++) {
                    for (int j2 = y-1-r; j2 <= y-1+r; j2++) {
                        a[j][j2] = tmp[j-(x-1-r)][j2-(y-1-r)];
                    }
                }
            }

            printmat(a, len);
        }
    }
}
