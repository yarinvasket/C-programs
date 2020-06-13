#include <stdio.h>
#include "Doctor.h"
#include "Hospital.h"
#include "Patient.h"
#pragma warning(disable : 4996)
int main() {
	Hospital* hos = newHospital();
	Doctor* doc = newDoctor("Lior", "Physiotherapy");
	Doctor* doc1 = newDoctor("Moshe", "Surgeon");
	Doctor* doc2 = newDoctor("Itzik", "Neurosurgeon");
	Doctor* doc3 = newDoctor("Ofir", "Psychiatrist");
	Patient* pat = newPatient("Lior", 2004, doc);
	Patient* pat1 = newPatient("Ofir", 2004, doc2);
	printPatient(pat);
	printf("Changed Lior's attending doctor\n");
	setAttendingDoctor(pat, doc1);
	printPatient(pat);
	addDoctor(hos, doc);
	addDoctor(hos, doc1);
	addDoctor(hos, doc2);
	addDoctor(hos, doc3);
	addPatient(hos, pat);
	addPatient(hos, pat1);
	printHospital(hos);
	removePatient(hos, pat1);
	printf("Fired Lior and sent Ofir home\n");
	fireDoctor(hos, doc);
	printHospital(hos);
	freeHospital(hos);
	return 0;
}