#pragma once
#include "Room.h"
#include "Customer.h"
#include "Reservation.h"
#define HOTEL_FLOORS 4
#define ROOMS_PER_FLOOR 4
#define MAX_RESERVATIONS_AMOUNT 50
#define MAX_CUSTOMERS_AMOUNT 50
typedef struct Hotel {
	Room* rooms[HOTEL_FLOORS][ROOMS_PER_FLOOR];
	Reservation* reservations[MAX_RESERVATIONS_AMOUNT];
	Customer* customers[MAX_CUSTOMERS_AMOUNT];
}Hotel;
void checkIn(Hotel* hotel);
void checkOut(Hotel* hotel, int roomNumber);
Hotel* newHotel();
void showHotelStatus(Hotel* hotel); 
void addCustomer(Hotel* hotel,Customer* new_customer);
void freeHotel(Hotel* hotel);
int getRoomNumber(Hotel* hotel, Customer* cust);

