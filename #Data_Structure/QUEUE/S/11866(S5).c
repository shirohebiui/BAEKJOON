#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 1001

typedef struct _double_node
{
	int key;
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

int rear = 0;
void insert(int key) {
    double_node *i = &nodes[rear++];
	i->key = key;
	i->prev = tail->prev;
	i->next = tail;
	tail->prev->next = i;
	tail->prev = i;
}

double_node *pop(int k, double_node *p) {
    for(int i=1; i<k; i++) {
        p = p->next;
    }
    int ret = p->key;
    p->next->prev = p->prev;
    p->prev->next = p->next;
    return p;
}

int main()
{
	init_dlist();

    int N, K;
    scanf("%d %d", &N, &K);
    for(int i=1; i<=N; i++) {
        insert(i);
    }
    head->next->prev = tail->prev;
    tail->prev->next = head->next;
    double_node *p = head->next;
    printf("<");
    for(int i=1; i<N; i++) {
        p = pop(K, p);
        printf("%d, ", p->key);
        p = p->next;
    }
    pop(K, p);
    printf("%d>\n", p->key);
    return 0;
}