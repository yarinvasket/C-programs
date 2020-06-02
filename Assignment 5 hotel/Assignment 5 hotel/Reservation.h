#pragma once
#include "Room.h"
#include "Customer.h"
#define DATE_FORMAT_LENGTH 10
typedef struct Reservation {
	char date[DATE_FORMAT_LENGTH];
	Customer* customer;
	int peopleInRoom;
	int breakfastReservedPeople;
	Room* room;
}Reservation;
Reservation* newReservation(char date[DATE_FORMAT_LENGTH], Customer* customer, int peopleInRoom, int breakfastPeople, Room* room);