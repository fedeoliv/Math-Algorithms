import java.util.*;
import java.io.*;
import java.math.*;

class Factorial {
   public static void main (String[] args) throws java.lang.Exception {
      BigInteger fact= BigInteger.ONE;
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt(); 
      
      for(int i = 2; i <= n; i++)
         fact = fact.multiply(new BigInteger(String.valueOf(i)));

      System.out.println(fact);
   }
}
