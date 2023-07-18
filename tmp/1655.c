#include <stdio.h>
#include <stdlib.h>

//좌우 가중치
int right_w = 0;
int left_w = 0;

typedef struct Node
{
	int key;
	struct Node *parent;
	struct Node *left;
	struct Node *right;
	int left_exist = 0;
} Node;

Node *root;
void init_dlist(void)
{
		root = (Node*)malloc(sizeof(Node));
}


Node *Insert_Node_in_order_of_size(int k)
{
	Node *s;
	Node *i;
	s = (Node*)malloc(sizeof(Node));
	i = (Node*)malloc(sizeof(Node));

	//가중치 부여
	if(k < root->key){
		left_w++;
	} else if(k >= root->key) {
		right_w++;
	}

	//노드 삽입 위치 탐색
	s = root;
	while(1)
	{
		if(k < s->key && s->left_exist != 0){
			s = s->left;
		} else {break;}

		if(k >= s->key && s->right_exist != 0){
			s = s->right;
		} else {break;}
	}

	//노드 삽입
	if(k < s->key){
		i->key = k;
		i->parent = s;
		s->left = i;
		s->left_exist
	} else if(k >= s->key) {
		i->key = k;
		i->parent = s;
		s->right = i;
	}

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
		printf("%d ", p->key);
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
	for(int j=0; j<max; j++)
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