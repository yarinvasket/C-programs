#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include"Doctor.h"
#pragma warning(disable : 4996)
Doctor* newDoctor(char* name, char* profession) {
	Doctor* doc = (Doctor*)(malloc(sizeof(Doctor)));
	doc->name=(char*)(calloc(sizeof(char)*strlen(name),1));
	doc->profession=(char*)(calloc(sizeof(char)*strlen(profession),1));
	strcpy(doc->name, name);
	strcpy(doc->profession, profession);
	return doc;
}
void printDoctor(Doctor* doc) {
	printf("Name: %s\nProfession: %s\n", doc->name, doc->profession);
}
bool doctorEquals(Doctor* p1, Doctor* p2) {
	return !(strcmp(p1->name, p2->name) + strcmp(p1->profession, p2->profession)) ;
}
void freeDoctor(Doctor* doc) {
	//free(doc->name);
	//free(doc->profession);
	free(doc);
}