/*
A pointer in C is a way to share a memory address among different contexts (primarily functions). They are primarily used whenever a function needs to modify the content of a variable, of which it doesn't have ownership. 
*/
#include <stdio.h>
#include <stdlib.h>

void update(int *a,int *b) {
    // Complete this function    
    int aux_a = 0;
    aux_a = *a + *b;
    *b = abs(*a - *b);
    *a = aux_a;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}

