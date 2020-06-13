#pragma once
#include <stdbool.h>
typedef struct ListNode {
	void* value;
	struct ListNode* next;
}ListNode;
bool hasNext(ListNode* node);
void* addNode(ListNode* head, void* value);