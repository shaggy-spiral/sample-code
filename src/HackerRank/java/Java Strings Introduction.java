/*
This exercise is to test your understanding of Java Strings.
*/
import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        
        Scanner sc=new Scanner(System.in);
        String A=sc.next();
        String B=sc.next();

        /* Enter your code here. Print output to STDOUT. */
        int sum = A.length() + B.length();
        System.out.println(sum);
        
        //2nd 
        int compare = 0;
        compare = A.compareTo(B);
        if(compare > 0) {
            System.out.println("Yes");    
        }
        else {
            System.out.println("No");
        }
            
        //3rd
        String capsA = A.substring(0,1);
        String capsB = B.substring(0,1);
        String A1 = A.substring(1);
        String B1 = B.substring(1);
        capsA = capsA.toUpperCase();
        capsB = capsB.toUpperCase();
        
        A = capsA + A1;
        B = capsB + B1;
        
        
        System.out.print(A +" ");
        System.out.println(B);
        
    }
}

