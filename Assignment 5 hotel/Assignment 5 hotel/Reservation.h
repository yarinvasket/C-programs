#pragma once
#include "Room.h"
#include "Customer.h"
struct Reservation {
	char date[10];
	struct Customer* customer;
	int peopleInRoom;
	int breakfastReservedPeople;
	struct Room* room;
};