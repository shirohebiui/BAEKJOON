#include <stdio.h>
#include <stdlib.h>
#define MAX 1001

typedef struct node {
	int key;
    int order;
	struct node *prev;
	struct node *next;
} node;

node nodes[MAX]; int rear;
node *head, *tail;

void init_dlist() {
    head = (node*)malloc(sizeof(node));
	tail = (node*)malloc(sizeof(node));
	head->next = tail;
	head->prev = head;
	tail->next = tail;
	tail->prev = head;
}

void insert_node(int k, int order) {
	node *s = head->next;
    node *i = &nodes[rear++];

	if(head->next == tail) {
		i->key = k;
        i->order = order;
        i->next = tail;
        i->prev = head;
		head->next = i;
		tail->prev = i;
	} else {
		while(1) {
			if(s->key > k)
				break;
			s = s->next;
			if(s==tail)
				break;
		}
		i->key = k;
        i->order = order;
		i->prev = s->prev;
		i->next = s;
		s->prev->next = i;
		s->prev = i;
	}
}

void print_all(node *p) {
	while(p != tail) {
		printf("%d %d\n", p->key, p->order);
		p=p->next;
	}
}
int P[MAX];
void set_P(node *p) {
    int order = 0;
	while(p != tail) {
        P[p->order] = order++;
		p=p->next;
	}
}

int main() {
    init_dlist();
    int N; scanf("%d", &N);
    for(int i=0; i<N; i++) {
        int input; scanf(" %d", &input);
        insert_node(input, i);
    }
    set_P(head->next);
    for(int i=0; i<N; i++) {
        printf("%d ", P[i]);
    }
    printf("\n");
    //print_all(head->next);
    return 0;
}
