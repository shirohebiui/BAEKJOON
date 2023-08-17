/*** doubly linked list ***/

#include <stdio.h>
#include <stdlib.h>

typedef struct _double_node
{
	int prio;
	struct _double_node *prev;
	struct _double_node *next;
} double_node;

double_node *head, *tail;

void init_dlist(void)
{
	head = (double_node*)malloc(sizeof(double_node));
	tail = (double_node*)malloc(sizeof(double_node));
	head->next = tail;
	head->prev = head;
	tail->next = tail;
	tail->prev = head;
}

double_node *Insert_double_node_in_order_of_size(int k)
{
	double_node *s;
	double_node *i;
	s = (double_node*)malloc(sizeof(double_node));
	i = (double_node*)malloc(sizeof(double_node));

	if(head->next == tail)
	{
		i->prio = k;
		i->prev = head->prev;
		i->next = tail->next;
		head->next = i;
		tail->prev = i;
	}
	else
	{
		s = head->next;
		while(1)
		{
			if(s->prio > k)
				break;
			s = s->next;
			if(s==tail)
				break;
		}
		i->prio = k;
		i->prev = s->prev;
		i->next = s;
		s->prev->next = i;
		s->prev = i;
	}
	return i;
}
void print_all(double_node *p)
{
	while(p != tail)
	{
		printf("%d\n", p->prio);
		p=p->next;
	}
}

int main(void)
{
	init_dlist();
    int N;
    scanf("%d", &N);
    int tmp;
    for(int i=0; i<N; i++)
    {
        scanf("%d", &tmp);
        Insert_double_node_in_order_of_size(tmp);
    }
	print_all(head->next);
    return 0;
}
