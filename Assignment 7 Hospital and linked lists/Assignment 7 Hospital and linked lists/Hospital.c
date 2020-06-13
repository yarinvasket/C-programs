#include "Hospital.h"
#include <string.h>
#include "Doctor.h"
#include <stdbool.h>
void freePatients(Node* nd);
void freeDoctors(Hospital*,Node*);
Hospital* newHospital() {
	Hospital* ptr = (Hospital*)malloc(sizeof(Hospital));
	ptr->doctors_head = NULL;
	ptr->patients_head = NULL;
	return ptr;
}
void printHospital(Hospital* hospital) {
	printf("Patients:\n");
	Node* pat = hospital->patients_head;
	while (pat!=NULL) {
		printPatient(pat->data);
		pat = pat->next;
	}
	printf("Doctors:\n");
	Node* doc=hospital->doctors_head;
	while (doc) {
		printDoctor(doc->data);
		doc = doc->next;
	}
}
void addPatient(Hospital* hospital,Patient* pat) {
	push(&hospital->patients_head, pat);
}
void addDoctor(Hospital* hospital,Doctor* doc) {
	push(&hospital->doctors_head, doc);
}
void fireDoctor(Hospital* hospital, Doctor* doc) {
	Node* tempHead = hospital->doctors_head;
	if (doctorEquals((Doctor*)(tempHead->data), doc)) {
		tempHead = hospital->doctors_head->next;
		free(doc);
		hospital->doctors_head = tempHead;
		return;
	}
	while (tempHead->next!=NULL) {
		if (doctorEquals((Doctor*)(tempHead->next->data), doc)) {
			Doctor* tmp = tempHead->next;
			tempHead->next = tempHead->next->next;
			free(doc);
			return;
		}
		tempHead = tempHead->next;
	}
}

void removePatient(Hospital* hos, Patient* pat) {
	Node* tempHead = hos->patients_head;
	if(tempHead!=NULL)
	if (patientEquals((Patient*)(tempHead->data), pat)) {
		hos->patients_head = hos->patients_head->next;
		free(pat);
		return;
	}
	while (tempHead->next != NULL) {
		if (patientEquals((Patient*)(tempHead->next->data), pat)) {
			tempHead->next = tempHead->next->next;
			free(pat);
			return;
		}
		tempHead = tempHead->next;
	}
}
void freeHospital(Hospital* hos) {
	freePatients(hos->patients_head);
	freeDoctors(hos,hos->doctors_head);
	free(hos);
}
void freePatients(Node* nd) {
	if (nd->next == NULL) {
		freePatient((Patient*)(nd->data));
		free(nd);
		return;
	}
	freePatients(nd->next);
}
void freeDoctors(Hospital* hos,Node* nd) {
	if (nd->next == NULL) {
		freeDoctor((Doctor*)(nd->data));
		free(nd);
		return;
	}
	freeDoctors(hos,nd->next);
}

