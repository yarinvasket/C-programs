#pragma once
#include "Room.h"
#include "Customer.h"
#include "Reservation.h"
#define HOTEL_FLOORS 4
#define ROOMS_PER_FLOOR 4
struct Hotel {
	struct Room rooms[HOTEL_FLOORS][ROOMS_PER_FLOOR];
	struct Reservation* reservations;
	struct Customer* customers;
};
void showHotelStatus(struct Hotel* hotel); 
void addCustomer(struct Customer* new_customer);

