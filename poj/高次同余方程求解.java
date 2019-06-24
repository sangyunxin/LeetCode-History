package src;

import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public  static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String s = input.nextLine();
        String[] ss = s.split(" ");
        for(int i = ss.length - 1; i > 0; i--){
            System.out.print(ss[i] + " ");
        }
        System.out.print(ss[0] + "\n");
    }
}
