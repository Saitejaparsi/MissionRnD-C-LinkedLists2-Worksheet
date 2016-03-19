/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1==nullptr&&head2==nullptr)
		return NULL;
	else
	{
		struct node *t1, *i, *j, *temp;
		int e;
		if (head1 == nullptr && head2 == nullptr)
			return NULL;
		else if (head1 == NULL)
			return head2;
		else if (head2 == NULL)
			return head1;
		else{
			for (t1 = head1; t1->next != NULL; t1 = t1->next);
			t1->next = head2;
			if (head1 != NULL){
				i = head1;
				while (i != NULL){
					e = 0;
					j = head1;
					temp = j;
					while (j->next != NULL){
						if ((j->next)->num < j->num)
						{
							if (j == head1){
								i = head1;
								j = j->next;
								head1 = j;
								i->next = j->next;
								head1->next = i;
							}
							else
							{
								i = j;
								j = j->next;
								i->next = j->next;
								j->next = i;
								temp->next = j;
							}
							e = 1;
						}
						temp = j;
						j = j->next;
					}
					if (e == 0)
						return head1;
				}
			}
		}
	}
}
