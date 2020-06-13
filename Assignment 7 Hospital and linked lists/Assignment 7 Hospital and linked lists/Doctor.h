#pragma once
#include <stdbool.h>
typedef struct Doctor {
	char* name;
	char* profession;
}Doctor;
Doctor* newDoctor(char* name, char* profession);
void printDoctor(Doctor* doc);
bool doctorEquals(Doctor* p1, Doctor* p2);
void freeDoctor(Doctor* doc);
