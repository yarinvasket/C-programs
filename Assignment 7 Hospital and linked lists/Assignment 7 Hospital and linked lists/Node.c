#include "Node.h"
void push(Node** head, void* data) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = *head;
	*head = temp;
}

void* pop(Node** head) {
	if (*head == NULL)return NULL;
	void* tempData = (*head)->data;
	Node* temp = *head;
	*head = (*head)->next;
	free(temp);
	return tempData;

}

Node* cloneList(const Node* head) {

	Node* newHead = malloc(sizeof(Node));
	Node* tempNode = newHead;

	do {

		tempNode->data = head->data;

		if (head->next != NULL) {
			tempNode->next = malloc(sizeof(Node));
			tempNode = tempNode->next;
		}

		head = head->next;

	} while (head != NULL);

	return newHead;

}