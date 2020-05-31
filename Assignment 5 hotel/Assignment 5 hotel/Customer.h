#pragma once
#define MAX_NAME_LENGTH 40
typedef struct Customer {
	int id;
	char name[MAX_NAME_LENGTH];
	long ccNumber;

}Customer;
Customer* newCostumer(int id, char name[MAX_NAME_LENGTH], long ccnumber);