#include "Room.h"
#include "Customer.h"
#include "Reservation.h"
#include "Hotel.h"
#include <stdlib.h>
#include <string.h>
Customer* newCostumer(int id, char* name, long ccnumber) {
	Customer* cust= malloc(sizeof(struct Customer));
	strcpy(cust->name, name);
	cust->id = id;
	cust->ccNumber = ccnumber;
	return cust;
}
void checkIn() {

}