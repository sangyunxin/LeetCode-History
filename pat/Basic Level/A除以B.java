import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        BigInteger A, B, Q, R;
        Scanner input = new Scanner(System.in);
        A = input.nextBigInteger();
        B = input.nextBigInteger();
        Q = A.divide(B);
        R = A.mod(B);
        System.out.println(Q.toString() + " " + R.toString());

    }
}
