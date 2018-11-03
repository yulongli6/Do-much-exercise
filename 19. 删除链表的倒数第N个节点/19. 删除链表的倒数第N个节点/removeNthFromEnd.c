#define _CRT_SECURE_NO_DEPRECATE 1

#include "stdio.h"
#include "stdlib.h"
struct ListNode {
	int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	if (!head->next)return NULL;
	struct ListNode* back = head;   //走在后面
	struct ListNode* mid = head;   //走在中间
	struct ListNode* front = head;//遍历时走在最前面的

	while (--n){
		front = front->next;
	}
	while (front->next != NULL){
		back = mid;
		mid = mid->next;
		front = front->next;
	}
	if (mid == back){
		head = mid->next;
	}
	else{
		back->next = mid->next;
	}
	free(mid);
	return head;
}


int main()
{
	int n = 3;
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));

	n1->next = n2; n2->next = n3; n3->next = n4; n4->next = NULL;
	n1->val = 1; n2->val = 2; n3->val = 3; n4->val = 4;

	removeNthFromEnd(n1, n);

	return 0;
}