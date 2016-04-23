/*
Given a string AA, print "Yes" if it is a palindrome, print "No" otherwise. The strings will consist lower case english letters only. The strings will have at most 50 characters.
*/

import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        
        Scanner sc=new Scanner(System.in);
        String A=sc.next();
        String B = "";
        /* Enter your code here. Print output to STDOUT. */
        int strlen = A.length();
        for( int i = strlen; i >0; i--) {
            B += A.substring(i-1,i);
        }
        // System.out.println(B);
        if( A.contentEquals(B)) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
