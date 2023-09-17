#include "customer.h"
#include <stdio.h>

void print_cust(customer_t* cust){
    // -> is the same as (*cust).name     it dereferences it
    printf("----- %d: %s -----", cust->id_num, cust->name);
    printf("==================================================\n");
    //printf("\tBalance: $%f\n", );

}