/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.
INPUTS:  A number.
OUTPUT: Create linked list from given number, each digit as a node.
ERROR CASES:
NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
};

typedef struct node NODE;

struct node * numberToLinkedList(int N) {
	struct node *head = NULL;
	struct node *curr;
	curr = (struct node*)malloc(sizeof(struct node));
	if (N == 0) {
		curr->num = N;
		curr->next = head;
		head = curr;
		return head;
	}
	else if (N < 0)
		N = abs(N);
	int dup = N;
	while (dup != 0) {
		curr->num = dup % 10;
		curr->next = head;
		head = curr;
		curr = (NODE *)malloc(sizeof(NODE));
		dup /= 10;
	}
	return head;
}