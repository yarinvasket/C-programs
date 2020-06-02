#include <stdio.h>
#include <stdbool.h>
#include "Room.h"
#include "Customer.h"
#include "Reservation.h"
#include "Hotel.h"

int main()
{
    Hotel* hotel = newHotel();
    Customer * lior=newCostumer(324294352, "lior", 2349874532);
    Customer * itzik=newCostumer(120124567, "itzik", 2432135436);
    Customer * moshe=newCostumer(675686342, "moshe", 234343534152);
    Customer * israel=newCostumer(656732234, "israel", 22334399721232);
    addCustomer(hotel, lior);
    addCustomer(hotel, itzik);
    addCustomer(hotel, moshe);
    addCustomer(hotel, israel);
    printf("Added four customers\n");
    showHotelStatus(hotel);
    checkIn(hotel);
    checkIn(hotel);
    showHotelStatus(hotel);
    printf("Checked out israel and Moshe\n");
    checkOut(hotel,getRoomNumber(hotel,israel));
    checkOut(hotel,getRoomNumber(hotel,moshe));
    showHotelStatus(hotel);
    checkIn(hotel);
    showHotelStatus(hotel);
    freeHotel(hotel);
    return 0;
}

