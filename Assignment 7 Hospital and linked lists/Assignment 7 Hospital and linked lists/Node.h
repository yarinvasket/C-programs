#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	void* data;
	struct Node* next;
} Node;
void* pop(Node** head);
void push(Node** head, void* data);
Node* cloneList(const Node* head);
