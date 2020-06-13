#pragma once
#include "Doctor.h"
#include<stdlib.h>
#include<stdio.h>
#include <stdbool.h>
typedef struct Patient {
	char* name;
	int birthYear;
	Doctor* doctor;

}Patient;
Patient* newPatient(char* name, int birthYear, Doctor* doc);
void printPatient(Patient* pat);
bool patientEquals(Patient* p1, Patient* p2);
void setAttendingDoctor(Patient* pat, Doctor* doc);
void freePatient(Patient* ptr);