package Luogu;

import java.util.Scanner;

public class P1563 {
    static class obj {
        public obj(int flag, String name) {
            this.flag = flag;
            this.name = name;
        }
        public int flag;
        public String name;
    }
    
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            int man = in.nextInt();
            int run = in.nextInt();
            
            obj a[] = new obj[man];
            for (int i = 0; i < man; i++) {
                a[i] = new obj(in.nextInt(), in.next());
            }
            
            int last = 0;

            for (int i = 0; i < run; i++) {
                int flag = in.nextInt();
                int time = in.nextInt();
                
                if(a[last].flag == flag){
                    last-=time;
                }else{
                    last+=time;
                }
                while(last>=man){
                    last-=man;
                }
                while(last<0){
                    last+=man;
                }

            }
            System.out.println(a[last].name);
        }
    }
}
