/*
In this problem you will test your knowledge of Java loops.
*/

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        int a = 0;
        int b = 0;
        int n = 0;
        for ( int i = 0; i < t; i++) {
            a = in.nextInt();
            b = in.nextInt();
            n = in.nextInt();
            for( int j = 1; j <= n; j++ ) {
                   int calc = a;
                   
                   for ( int inter = 1; inter <= j; inter ++) {
                       calc += (Math.pow(2, inter - 1) * b); 
                   }
                
                System.out.print(calc + " ");    
            }
            System.out.println();
            
        }
      
    }
}
