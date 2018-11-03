#define _CRT_SECURE_NO_DEPRECATE 1

#include<stdio.h>
#include<stdlib.h>
struct ListNode {
     int val;
   struct ListNode *next;
 };

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* cur1 = l1;
	struct ListNode* cur2 = l2;
	struct ListNode* result = NULL;
	struct ListNode* tail = NULL;
	int temp = 0;
	while (cur1 != NULL && cur2 != NULL){
		struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);
		node->next = NULL;
		if (cur1->val + cur2->val + temp > 9){
			node->val = cur1->val + cur2->val + temp - 10;
			if (tail == NULL){
				result = node;
			}
			else{
				tail->next = node;
			}

			tail = node;
			temp = 1;
		}
		else{
			node->val = cur1->val + cur2->val + temp;
			if (tail == NULL){
				result = node;
			}
			else{
				tail->next = node;
			}
			tail = node;
			temp = 0;
		}

		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	if (cur1 == NULL && cur2 != NULL)
	{

		while (cur2 != NULL)
		{
			struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);
			node->next = NULL;
			if (cur2->val + temp > 9){
				node->val = cur2->val + temp - 10;
				tail->next = node;

				tail = node;
				temp = 1;
			}
			else{
				node->val = cur2->val + temp;
				tail->next = node;

				tail = node;
				temp = 0;
			}
			cur2 = cur2->next;
		}
	}
	if (cur2 == NULL && cur1 != NULL)
	{
		while (cur1 != NULL)
		{
			struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);
			node->next = NULL;
			if (cur1->val + temp > 9){
				node->val = cur1->val + temp - 10;
				tail->next = node;

				tail = node;
				temp = 1;
			}
			else{
				node->val = cur1->val + temp;
				tail->next = node;
				tail = node;
				temp = 0;
			}

			cur1 = cur1->next;
		}
	}
	if (temp == 1)
	{
		struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);
		node->next = NULL;
		node->val = 1;
		tail->next = node;
		tail = node;

	}
	return result;
}


int main()
{
	struct ListNode* l1;
	struct ListNode* l2;
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n6 = (struct ListNode*)malloc(sizeof(struct ListNode));
	l1 = n1; n1->next = n2; n2->next = n3; n3->next = NULL;
	n1->val = 9; n2->val = 9; n3->val = 9;
	l2 = n4; n4->next = NULL;
	n4->val = 1;
	struct ListNode* ret = addTwoNumbers(l1, l2);
	return 0;
}