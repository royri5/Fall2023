#ifndef 		__H__CUSTOMER__
#define			__H__CUSTOMER__
#include <stdlib.h>

typedef struct tn {
	unsigned int cid_num;
	unsigned int tid_num;
	double amount;
} transaction_t;

typedef struct cm {
	unsigned int id_num;
	char* name;
	char* email;
	double money;
	transaction_t* transactions;
} customer_t;

void print_cust(customer_t* cust);

customer_t* copy_cust(customer_t orig);

#endif
