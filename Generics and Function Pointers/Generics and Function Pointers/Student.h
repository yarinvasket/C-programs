typedef struct Student {
	char* name;
	long id;
	int age;
	float finalGrade;
}Student;
Student* newStudent(char*, long, int, float);