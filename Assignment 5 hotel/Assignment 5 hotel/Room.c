#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include "Room.h"
Room* newRoom(int people, int breakfastPeople) {
	Room* room = (Room*)calloc(1, sizeof(Room));
	room->occupied = false;
	room->people = people;
	room->breakfastPeople = breakfastPeople;
	return room;
}