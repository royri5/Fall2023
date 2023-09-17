#include <stdio.h>
#include <stdlib.h>

#include "customer.h"
#include "customer.c"


int main(int argc, char** argv){
	customer_t hank;
	hank.id_num = 1;
	hank.money = 100.00;
	hank.name = "Hank Henry Hankerson";

	customer_t* henrietta;
	henrietta = malloc(sizeof(customer_t));
	henrietta->id_num = 2;
	henrietta->money = 250.00;
	henrietta->name = "Henrietta TwoTs VonHofferson";

	transaction_t hank_open;
	transaction_t* henrietta_open;

	print_cust(&hank);
	print_cust(henrietta);

	customer_t* tttonya = copy_cust(hank);	
	tttonya->id_num = 3;
	hank.money = 50;
	print_cust(&hank);
	print_cust(tttonya);
	free(tttonya);
	
}
