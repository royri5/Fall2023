#ifndef __H__CUSTOMER__
#define __H__CUSTOMER__
#include <stdlib.h>

// typedefs are alises for structs
typedef struct transaction {
    unsigned int c_id;
    unsigned int t_id;
    double amount;
} transaction_t;

typedef struct customer {
    unsigned int id_num;
    //dynamic char array
    char* name;
    double amount;
    //dynamic transaction array
    transaction_t* transactions;
    size_t num_transactions;
} customer_t;

void print_cust(customer_t* cust);

#endif