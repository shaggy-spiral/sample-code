/*
An array is a series of elements of the same type placed in contiguous memory locations that can be individually referenced by adding an index to a unique identifier.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n = 0;
    scanf("%d",&n);
    int elem[n];
    for( int j = 0; j < n ;j++)
        {
        scanf("%d", &elem[j]);
    }
    
    for(int i = n-1; i >= 0; i--)
        {
        printf("%d ",elem[i]);
    }
    return 0;
}
