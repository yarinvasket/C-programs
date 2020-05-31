#include "Room.h"
#include "Customer.h"
#include "Reservation.h"
#include "Hotel.h"
#include <stdlib.h>
#include <stdbool.h>

Reservation* newReservation(char date[DATE_FORMAT_LENGTH], Customer* customer, int peopleInRoom, int breakfastPeople, Room* room) {
	Reservation* reser = (Reservation*)calloc(1, sizeof(Reservation));
	reser->breakfastReservedPeople = breakfastPeople;
	reser->customer = customer;
	reser->peopleInRoom = peopleInRoom;
	reser->room = room;
	for (int i = 0;i < DATE_FORMAT_LENGTH;i++) {
		reser->date[i] = date[i];
	}
	return reser;
}
void freeReservation(Reservation* reservation) {
	free(&reservation->peopleInRoom);
	free(&reservation->breakfastReservedPeople);
	free(&reservation->date);
}
