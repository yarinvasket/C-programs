#pragma once
#include "Room.h"
#include "Customer.h"
#include "Reservation.h"
#define HOTEL_FLOORS 4
#define ROOMS_PER_FLOOR 4
typedef struct Hotel {
	Room* rooms[HOTEL_FLOORS][ROOMS_PER_FLOOR];
	Reservation* reservations;
	Customer** customers;
}Hotel;
void checkIn();
Hotel* newHotel(Reservation* reservations, Customer** customers);
void showHotelStatus(Hotel* hotel); 
void addCustomer(Hotel* hotel,Customer* new_customer);

