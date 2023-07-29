#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 1000000

typedef struct _double_node
{
	long key;
	struct _double_node *prev;
	struct _double_node *next;
} double_node;

double_node nodes[MAX_NODES]; //삽입에 쓸 노드
double_node *head, *tail;

//리스트 초기화
void init_dlist(void)
{
    head = (double_node*)malloc(sizeof(double_node));
	tail = (double_node*)malloc(sizeof(double_node));
	head->next = tail;
	head->prev = head;
	tail->next = tail;
	tail->prev = head;
}



long rear = 0; //현재 노드 최대갯수 (head, tail제외)
double_node *Insert_double_node_in_order_of_size(int k)
{
	double_node *s = head->next;
    double_node *i = &nodes[rear++];

	if(head->next == tail)
	{
		i->key = k;
        i->next = tail;
        i->prev = head;
		head->next = i;
		tail->prev = i;
	}
	else
	{
        //삽입하고자하는 값보다 큰값을 탐색
        //조건을 만족한곳의 앞에 노드 삽입
		while(1)
		{
			if(s->key > k)
				break;
			s = s->next;
			if(s==tail)
				break;
		}
		i->key = k;
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
		printf("%ld\n", p->key);
		p=p->next;
	}
}

int main()
{
	init_dlist();

    long N;
    scanf("%ld", &N);

    long tmp;
    while(N--) {
        scanf("%ld", &tmp);
        Insert_double_node_in_order_of_size(tmp);
    }

	print_all(head->next);
    return 0;
}