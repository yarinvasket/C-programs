#include "Room.h"
#include "Customer.h"
#include "Reservation.h"
#include "Hotel.h"
#include <stdlib.h>
#include <stdbool.h>

Reservation* newReservation(char date[DATE_FORMAT_LENGTH], Customer* customer, int peopleInRoom, int breakfastPeople, Room* room) {
	Reservation* reser = malloc(sizeof(Reservation));
	reser->customer = customer;
	reser->breakfastReservedPeople = breakfastPeople;
	reser->peopleInRoom = peopleInRoom;
	reser->room = room;
	for (int i = 0;i < DATE_FORMAT_LENGTH;i++)
		reser->date[i] = date[i];
	return reser;
}