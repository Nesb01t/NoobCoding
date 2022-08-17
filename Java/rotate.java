package Java;

public class rotate {

    public static void main(String[] args) {
        int a[][] = spawn_rotate(5);
        printmat(a, 5);
        a = rotate_(a, 5, 2, 2, 1, 0);
        printmat(a, 5);
    }

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
    static int[][] rotate_(int a[][]){ // 旋转矩阵
        int newmat[][] = new int[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                newmat[i][j] = a[2-j][i];
            }
        }
        return newmat;
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
    static int[][] rotate_(int a[][], int len, int x, int y, int r, int z){ // 旋转矩阵, 带长度, 以x,y为中心, 宽度为r, z=0为顺时针, z=1为逆时针
        int newmat[][] = new int[len][len];
        
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                newmat[i][j] = a[i][j];
            }
        }
        for (int i = y-r; i < y+r+1; i++) {
            for (int j = x-r; j < x+r+1; j++) {
                if(z==0) {
                    newmat[i][j] = a[x+r-j][i];
                }else if(z==1) {
                    newmat[i][j] = a[j][y+r-i];
                }
            }
        }
        return newmat;
    }
    static void printmat(int a[][]){ // 打印矩阵
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print(a[i][j]+" ");
            }
            System.out.println();
        }
    }
    static void printmat(int a[][], int len){ // 打印矩阵
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                System.out.print(a[i][j]+" ");
            }
            System.out.println();
        }
    }
}
