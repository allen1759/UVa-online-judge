import java.util.Scanner;
import java.math.BigInteger;

public class test 
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);
        String a, b;
        while( cin.hasNext() ) {
            a = cin.next();
            b = cin.next();
            BigInteger Biga = new BigInteger(a);
            BigInteger Bigb = new BigInteger(b);
            System.out.println(Biga.multiply(Bigb));
        }
    }
}
