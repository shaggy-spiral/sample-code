/*
Java's System.out.printf function can be used to print formatted output. The purpose of this exercise is to test your understanding of formatting output using printf.
*/
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
            Scanner sc=new Scanner(System.in);
            System.out.println("================================");
            for(int i=0;i<3;i++)
            {
                String s1=sc.next();
                int x=sc.nextInt();
                //Complete this line
                int nBlank = 15 - s1.length(); 
                String num = "";
                String blank = "";
                while ( nBlank > 0 ) {
                    blank = blank + " ";
                    nBlank--;
                }
                System.out.print(s1 + blank);
                if ( ( x > 99 ) ){
                    num += x;
                }
                if ( ( x < 100 ) && ( x > 9) ) {
                    num = "0" + x; 
                }    
                if ( ( x < 10 ) ) {
                    num = "00" + x; 
                }    
                System.out.println(num);
            }
            System.out.println("================================");

    }
}
