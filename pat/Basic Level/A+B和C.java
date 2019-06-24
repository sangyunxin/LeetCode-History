import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int n;
        BigInteger a, b, c;

        n = input.nextInt();
        for(int i = 1; i <= n; i++){
            a = input.nextBigInteger();
            b = input.nextBigInteger();
            c = input.nextBigInteger();

            if(a.add(b).compareTo(c) > 0)
                System.out.println("Case #" + i + ": true");
            else
                System.out.println("Case #" + i + ": false");
        }
    }
}
