#include <stdio.h>
#include <stdlib.h>
#include "customer.h"

void print_cust(customer_t* cust){
	printf("----- %d : %s -----\n", cust->id_num, cust->name);
	printf("=============================================================\n");
	printf("\tBalance: %f\n\n", cust->money);
}

customer_t* copy_cust(customer_t orig){
	customer_t* tmp = malloc(sizeof(customer_t));
	int i = 0;
	while(i < sizeof(customer_t)) {
		*(tmp+i) = *(&orig+i);
		i++;
	}

	return tmp;
}
