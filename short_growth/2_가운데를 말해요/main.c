#include <stdio.h>
#include <stdlib.h>

//0이면 짝수 1이면 홀수
int count = 1;

typedef struct Node
{
	int key;
	struct Node *prev;
	struct Node *next;
} Node;

Node *head, *tail, *center;

void init_dlist(int k)
{
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	center = (Node*)malloc(sizeof(Node));
	head->next = center;
	head->prev = head;
	tail->next = tail;
	tail->prev = center;
	center->next = tail;
	center->prev = head;
	
	center->key = k;
}

Node *Insert_Node_in_order_of_size(int k)
{
	Node *s;
	Node *i;
	s = (Node*)malloc(sizeof(Node));
	i = (Node*)malloc(sizeof(Node));
//노드를 오름차순 정렬하기위해 탐색
	
	//중앙 좌측 탐색 head~tail
	s = head->next;
	while(1){
		if(s->key > k)
			break;
		s = s->next;
		if(s==center)
			break;
	}

	
	//현재 노드 s_node의 이전에 새로운 노드 삽입
	i->key = k;
	i->prev = s->prev;
	i->next = s;
	s->prev->next = i;
	s->prev = i;
		
	
	//0 -> 짝, 1 -> 홀
	count = ++count % 2;
	return i;
}

void print_center(void)
{
	//현재 노드 갯수가 짝수
	if(count == 0)
	{
		if(center->key < center->next->key)
			printf("%d\n", center->key);
		else
			printf("%d\n", center->next->key);
	}
	//현재 노드 갯수가 홀수
	else
		printf("%d\n", center->key);
}
void print_all(Node *p)
{
	printf("\n");
	while(p != tail)
	{
		printf(" %d     ", p->key);
		p=p->next;
	}
}
int main()
{

    /*
	해야할일
    input 받을때마다 input된것중 중간값output
    */

   	//입력받을 갯수
	int max;
	scanf("%d", &max);

	//값 입력
	int key;
	scanf("%d", &key);
	init_dlist(key);
	print_center();
	for(int j=0; j<max-1; j++)
	{
		scanf("%d", &key);
		Insert_Node_in_order_of_size(key);
		//print_center();
	}
		print_all(head->next);
		printf("\n");
		printf("%d\n", center->key);
		center = center->prev;
		printf("%d\n", center->key);
    return 0;
}