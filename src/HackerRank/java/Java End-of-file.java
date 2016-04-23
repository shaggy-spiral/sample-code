/*
The challenge here is to read nn lines of input until you reach EOF, then number and print all nn lines of content.
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
        int i = 1;
      //  while( EOF != true) {
            while (sc.hasNext() == true)
                {
                System.out.println( i + " " + sc.nextLine());
                i++;
            }
        
    }
}
