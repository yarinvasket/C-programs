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
				Room* room = newRoom(0, 0);
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
				printf("Room %d%d is occupied, it has %d people of which %d assigned for breakfast \n"
					,i + 1, j, hotel->rooms[i][j]->people, hotel->rooms[i][j]->breakfastPeople);
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
	for(int i=0;i<MAX_CUSTOMERS_AMOUNT;i++){
		if (hotel->customers[i] == NULL)break;
		int j = 0;
		printf("%d:%s\n", i, hotel->customers[i]->name);
	}
	int customerNumber = 0;
	scanf_s("%d", &customerNumber);
	printf("Please enter the amount of people for the room:\n");
	int people = 0;
	int breakfast = 0;
	scanf_s("%d", &people);
	printf("Please enter the amount of people that will have breakfast:\n");
	scanf_s("%d", &breakfast);
	for (int i = 0;i < HOTEL_FLOORS;i++) {
		for (int j = 0;j < ROOMS_PER_FLOOR;j++) {
			if (!hotel->rooms[i][j]->occupied) {
				newReservation("00/00/0000",hotel->customers[customerNumber] , people, breakfast, hotel->rooms[i][j]);
				return;
			}
		}
	}
	printf("We could not complete the order since the hotel is fully occupied.\n");
	
}
void checkOut(Hotel* hotel, int roomNumber) {
	for (int i = 0;i < HOTEL_FLOORS;i++) {
		for (int j = 0;j < ROOMS_PER_FLOOR;j++) {
			if (!roomNumber--) {
				hotel->rooms[i][j]->breakfastPeople = 0;
				hotel->rooms[i][j]->people = 0;
				hotel->rooms[i][j]->occupied = false;
			}
		}
	}
}

void freeHotel(Hotel* hotel) {
	//free rooms
	/*
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
		freeReservation(hotel->reservations[i]);
	}
	free(hotel);*/
	
}


