#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include "Room.h"
Room* newRoom(int people, int breakfastPeople) {
	Room* room = malloc(sizeof(Room));
	room->people = people;
	room->breakfastPeople = breakfastPeople;
	room->occupied = false;
	return room;
}
void checkOut() {

}