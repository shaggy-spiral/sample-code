/*
Given a string, find number of words in that string. For this problem a word is defined by a string of one or more english alphabets. 
*/
import java.util.Scanner;
import java.util.regex.*;

public class Solution
{
   public static void main(String[] args){
      Scanner in = new Scanner(System.in);
      int testCases = Integer.parseInt(in.nextLine());
      
      while(testCases>0){
         String pattern = in.nextLine();
         //Write your code
         try {
         Pattern pat = Pattern.compile(pattern);
          } catch (PatternSyntaxException e) {
              System.out.println("Invalid");
              continue;
          }
          System.out.println("Valid"); 
      
      }
   }
}
