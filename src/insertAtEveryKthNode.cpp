/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (head==nullptr||K<1)
		return NULL;
	else
	{
		int len=0;
		struct node *t,*temp=NULL,*i,*temp1=NULL;
		for (t= head; t!= NULL; t = t->next, len++);
		if (K > len)
			return head;
		int c = 1;
		for (i = head; i != NULL;)
		{
			if (c == K)
			{
				temp = (struct node *)malloc(sizeof(struct node));
				temp->num = K;
				temp1 = i->next;
				i->next = temp;
				temp->next = temp1;
				i = temp1;
				c = 1;
			}
			else
			{
				i = i->next;
				c++;
			}
		}
		return head;
	}
}
