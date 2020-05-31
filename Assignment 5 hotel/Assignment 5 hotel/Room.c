#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include "Room.h"
Room* newEmptyRoom() {
	return newRoom(false, 0, 0);
}
Room* newRoom(bool occupied, int people, int breakfastPeople) {
	Room* room = (Room*)calloc(1, sizeof(Room));
	room->occupied = occupied;
	room->people = people;
	room->breakfastPeople = breakfastPeople;
	return room;
}