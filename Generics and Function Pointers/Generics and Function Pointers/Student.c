#include "Student.h"
#include<string.h>
#pragma warning(disable : 4996)
Student* newStudent(char* name, long id, int age, float finalGrade) {
	Student* ptr = (Student*)malloc(sizeof(Student));
	strcpy(ptr->name, name);
	ptr->id = id;
	ptr->age = age;
	ptr->finalGrade = finalGrade;
	return ptr;
}