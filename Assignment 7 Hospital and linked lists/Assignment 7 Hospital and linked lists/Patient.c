#include "Patient.h"
Patient* newPatient(char* name, int birthYear, Doctor* doc) {
	Patient* pat = (Patient*)(malloc(sizeof(Patient)));
	pat->doctor = doc;
	pat->birthYear = birthYear;
	pat->name = (char*)(malloc(strlen(name) * sizeof(char)));
	strcpy(pat->name, name);
	return pat;
}
void printPatient(Patient* pat) {
	printf("Name: %s|Birth year: %d|Attended by: %s\n", pat->name, pat->birthYear, pat->doctor->name);
}
void setAttendingDoctor(Patient* pat, Doctor* doc) {
	pat->doctor = doc;
}
bool patientEquals(Patient* p1, Patient* p2) {
	return !(strcmp(p1->name, p2->name) + p1->birthYear!=p2->birthYear);
}
;
void freePatient(Patient* ptr) {
	free(ptr);
}