#include <stdio.h>
#include <stdbool.h>
#include "Room.h"
#include "Customer.h"
#include "Reservation.h"
#include "Hotel.h"

int main()
{
    Hotel* hotel = newHotel();
    char arr[40] = "lior";
    Customer * lior=newCostumer(1, arr, 23432);
    addCustomer(hotel, lior);
    checkIn(hotel);
    showHotelStatus(hotel);
    freeHotel(hotel);
    return 0;
}

