#include "Room.h"
#include "Customer.h"
#include "Reservation.h"
#include "Hotel.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
Hotel* newHotel() {
	Hotel* hotel = (Hotel*)calloc(1,sizeof(Hotel));
	if (hotel) {
		for (int i = 0;i < HOTEL_FLOORS;i++) {
			for (int j = 0;j < ROOMS_PER_FLOOR;j++) {
				Room* room = newEmptyRoom();
				hotel->rooms[i][j] = room;
			}
		}
		for (int i = 0;i < MAX_CUSTOMERS_AMOUNT;i++) {
			hotel->customers[i] = NULL;
		}
		for (int i = 0;i < MAX_RESERVATIONS_AMOUNT;i++) {
			hotel->reservations[i] = NULL;
		}
	}
	return hotel;
}
void showHotelStatus(Hotel* hotel) {
	for (int i = 0;i < HOTEL_FLOORS;i++) {
		for (int j = 0;j < ROOMS_PER_FLOOR;j++) {
			if (hotel->rooms[i][j]->occupied)
				printf("Room %d is occupied, it has %d people of which %d assigned for breakfast \n"
					,(i * ROOMS_PER_FLOOR)+j, hotel->rooms[i][j]->people, hotel->rooms[i][j]->breakfastPeople);
		}
	}
}
void addCustomer(Hotel* hotel, Customer* new_customer) {
	for (int i = 0;i < MAX_CUSTOMERS_AMOUNT;i++) {
		if (hotel->customers[i] == NULL) {
			hotel->customers[i] = new_customer;
			return;
		}
	}
}
void checkIn(Hotel* hotel) {
	printf("Please enter your hotel account number according to the list, if you don't have one, sign up as a customer:\n");
	int i = 0;
	for(;i<MAX_CUSTOMERS_AMOUNT;i++){
		if (hotel->customers[i] == NULL) break;
			printf("%d:%s\n", i, hotel->customers[i]->name);
		
	}
	int customerNumber = 0;
	while (1) {
		scanf_s("%d", &customerNumber);
		if (customerNumber < i && customerNumber >= 0)break;
		printf("Please choose an existing customer:\n");
	}
	i = 0;
	printf("Please enter the amount of people for the room:\n");
	int people = 0;
	int breakfast = 0;
	scanf_s("%d", &people);
	printf("Please enter the amount of people that will have breakfast:\n");
	scanf_s("%d", &breakfast);
	for (i = 0;i < HOTEL_FLOORS;i++) {
		for (int j = 0;j < ROOMS_PER_FLOOR;j++) {
			if (!hotel->rooms[i][j]->occupied) {
				hotel->rooms[i][j] = newRoom(true, people, breakfast);
				for (int n = 0;n < MAX_RESERVATIONS_AMOUNT;n++) {
					if (hotel->reservations[n] == NULL) {
						hotel->reservations[n] = newReservation("00/00/0000", hotel->customers[customerNumber], people, breakfast, hotel->rooms[i][j]);
						break;
					}
				}
				
				return;
			}
		}
	}
	printf("We could not complete the order since the hotel is fully occupied.\n");
}
void checkOut(Hotel* hotel, int roomNumber) {
	if (roomNumber == -1)return;
	Room* room = newEmptyRoom();
	int i = 0;
	int j = 0;
	for (;i < HOTEL_FLOORS;i++) {
		for (;j < ROOMS_PER_FLOOR;j++) {
			if (!roomNumber--) {
				goto out;
			}
		}
	}
	out:
	for (int n = 0;n < MAX_RESERVATIONS_AMOUNT;n++) {
		if (hotel->reservations[n] != NULL && hotel->reservations[n]->room==room) {
			hotel->reservations[n] = NULL;
			break;
		}
	}
	hotel->rooms[i][j] = newEmptyRoom();
}
int getRoomNumber(Hotel* hotel, Customer* cust) {
	int n = 0;
	for (;n < MAX_RESERVATIONS_AMOUNT;n++) {
		if (hotel->reservations[n]!=NULL&&hotel->reservations[n]->customer == cust) {
			break;
		}
	}
	for (int i = 0;i < HOTEL_FLOORS;i++) {
		for (int j = 0;j < ROOMS_PER_FLOOR;j++) {
			if (hotel->rooms[i][j]==hotel->reservations[n]->room) {
				return i*ROOMS_PER_FLOOR+j;
			}
		}
	}
	return -1;
}


void freeHotel(Hotel* hotel) {
	//free rooms
	
	for (int i = 0;i < HOTEL_FLOORS;i++) {
		for (int j = 0;j < ROOMS_PER_FLOOR;j++) {
			free(hotel->rooms[i][j]);
		}
	}
	//free customers
	for (int i = 0;i < MAX_CUSTOMERS_AMOUNT;i++) {
		free(hotel->customers[i]);
	}
	//free reservations
	for (int i = 0;i < MAX_RESERVATIONS_AMOUNT;i++) {
		free(hotel->reservations[i]);
	}
	free(hotel);
	
}


