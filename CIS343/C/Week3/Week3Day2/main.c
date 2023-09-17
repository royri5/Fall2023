#include <stdio.h>
#include <stdlib.h>
#include "customer.h"

int main(int argc, char** argv){

    customer_t hank;
    customer_t* henrietta;
    transaction_t hank_open;
    transaction_t* henrietta_open;

    printf("%zu\n", sizeof hank);
    printf("%zu\n", sizeof henrietta);
    printf("%zu\n", sizeof hank_open);
    printf("%zu\n", sizeof henrietta_open);
}