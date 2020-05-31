#include "Customer.h"
#include <stdlib.h>
#include <string.h>
struct Customer* newCostumer(int id, char name[MAX_NAME_LENGTH], long ccnumber) {
	Customer* cust = (Customer*)malloc(1,sizeof(Customer));
	if (cust) {
		strcpy_s(cust->name, MAX_NAME_LENGTH, name);
		cust->id = id;
		cust->ccNumber = ccnumber;
	}
	return cust;
}