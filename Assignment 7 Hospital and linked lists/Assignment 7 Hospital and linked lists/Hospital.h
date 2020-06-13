#pragma once
#include "Patient.h"
#include "Doctor.h"
#include "Node.h"
typedef struct Hospital {
	Node* patients_head;
	Node* doctors_head;
}Hospital;
void printHospital(Hospital* hospital);
Hospital* newHospital();
void addPatient(Hospital* hospital, Patient* pat);
void addDoctor(Hospital* hospital, Doctor* doc);
void fireDoctor(Hospital* hospital, Doctor* doc);
void removePatient(Hospital* hos, Patient* pat);
void freeHospital(Hospital* hos);