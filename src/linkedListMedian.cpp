/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	if (head==nullptr)
		return -1;
	else
	{
		if (head->next == NULL)
			return head->num;
		else if (head->next->next == NULL)
			return (head->num + head->next->num)/2;
		struct node *i = head, *j = head->next->next;
		while (j != NULL)
		{
			if (j->next == NULL)
				return i->next->num;
			else if (j->next->next == NULL)
				return (i->next->num + i->next->next->num) / 2;
			else
				i = i->next, j = j->next->next;
		}

	}
}
