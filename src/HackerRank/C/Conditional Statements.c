/*
if and else are two of the most heavily used conditionals in C/C++. They are used to execute zero or one statement among many statements. 
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int x;
    scanf("%d",&x);
    if ( x == 1 ) {
        printf("one");
    } else if ( x == 2 ) {
        printf("two");
    } else if ( x == 3 ) {
        printf("three");
    } else if ( x == 4 ) {
        printf("four");
    } else if ( x == 5 ) {
        printf("five");
    } else if ( x == 6 ) {
        printf("six");
    } else if ( x == 7 ) {
        printf("seven");
    } else if ( x == 8 ) {
        printf("eight");
    } else if ( x == 9 ) {
        printf("nine");
    } else {
        printf("Greater than 9");
    }
   
        
        
        
        
        return 0;
}
