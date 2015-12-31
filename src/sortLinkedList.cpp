/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};


struct node * sortLinkedList(struct node *head) {

	if (head == NULL)
		return NULL;
	int flag = 0;
	struct node *curr, *temp = NULL;
	do {
		flag = 0;
		curr = head;
		while (curr->next != temp){
			if (curr->next->num < curr->num){
				flag = 1;
				int dup = curr->num;
				curr->num = curr->next->num;
				curr->next->num = dup;
			}
			curr = curr->next;
		}
		temp = curr;
	} while (flag == 1);
	return head;

}