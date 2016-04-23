/*
Given a string, find out the lexicographically smallest and largest substring of length k.
*/
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        String aux1 = ""; 
        String maior = "A";
        String menor = "Z";
        int k = sc.nextInt();
        // temp
        int str_length = str.length();
        
        
        for (int i = 0; i <= str_length - k; i++) {
            aux1 = str.substring(i, i + k);
            if ( aux1.compareTo(maior) >= 0) {
                maior = aux1;
            }
            if ( aux1.compareTo(menor) <= 0) {
                menor = aux1;
            }
        }
        System.out.println(menor);
        System.out.println(maior);
        
    }
}
