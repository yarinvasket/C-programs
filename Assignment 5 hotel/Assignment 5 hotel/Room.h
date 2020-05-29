#pragma once
#include <stdbool.h>
typedef struct Room {
	bool occupied;
	int people;
	int breakfastPeople;

}Room;
Room* newRoom(int people, int breakfastPeople);
void checkOut();


