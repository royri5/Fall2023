#include <stdio.h>

int main(int argc, char** argv) {
    int a = 20;
    int* b = &a;
    int c[2];
    int* d = &c[1];
    c[0] = 0;
    c[1] = 0;
    c[1] = 2;
    c[0] = (++*b**(c+1));
    printf("c[0]: %d\n", c[0]);
}