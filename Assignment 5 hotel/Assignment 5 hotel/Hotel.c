#include "Room.h"
#include "Customer.h"
#include "Reservation.h"
#include "Hotel.h"
#include <stdlib.h>
#include <stdbool.h>
Hotel* newHotel(Reservation* reservations, Customer** customers) {
	Hotel* hotel = malloc(sizeof(Hotel));
	for (int i = 0;i < HOTEL_FLOORS;i++) {
		for (int j = 0;j < ROOMS_PER_FLOOR;j++) {
			hotel->rooms[i][j] = malloc(newRoom(0, 0));
		}
	}
	hotel->customers = customers;
	hotel->reservations = reservations;
	return hotel;
}
void showHotelStatus(Hotel* hotel) {
	for (int i = 0;i < HOTEL_FLOORS;i++) {
		for (int j = 0;j < ROOMS_PER_FLOOR;j++) {
			if (hotel->rooms[i][j]->occupied)
				printf("Room %d%d is occupied, it has %d people of which %d assigned for breakfast \n"
					,i + 1, j, hotel->rooms[i][j]->people, hotel->rooms[i][j]->breakfastPeople);
		}
	}
}
void addCustomer(Hotel* hotel,Customer* new_customer) {
	int i = 0;
	while (*(hotel->customers + (i++))) {}
	*(hotel->customers +i - 1) = new_customer;
}
void checkIn(Hotel* hotel) {
	int i = 0; 
	printf("Please choose your hotel account, if you don't have one, sign up as a customer:\n");
	while (*(hotel->customers + i)) {
		printf("%s", *(hotel->customers + i)->name);
			i++;
	}
	
}