#pragma once
typedef struct Customer {
	int id;
	char* name;
	long ccNumber;

}Customer;
Customer* newCostumer(int id, char* name, long ccnumber);