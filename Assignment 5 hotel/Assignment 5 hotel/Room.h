#pragma once
#include <stdbool.h>
typedef struct Room {
	bool occupied;
	int people;
	int breakfastPeople;

}Room;
Room* newEmptyRoom();
Room* newRoom(bool occupied, int people, int breakfastPeople);
bool equals(Room* ptr1, Room* ptr2);

