/*** deck ***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _double_node
{
	int key;
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

void push_front(int k) //insert k after head
{
    double_node *i = (double_node*)malloc(sizeof(double_node));
    i->key = k;
    i->prev = head;
    i->next = head->next;
    head->next->prev = i;
    head->next = i;
}

void push_back(int k) //insert k before back
{
    double_node *i = (double_node*)malloc(sizeof(double_node));
    i->key = k;
    i->prev = tail->prev;
    i->next = tail;
    tail->prev->next = i;
    tail->prev = i;
}
int empty();
int pop_front()
{
    if(empty()) {
        return -1;
    }
    double_node *i = head->next;
    int ret = i->key;
    head->next = i->next;
    i->next->prev = head;
    free(i);

    return ret;
}

int pop_back()
{
    if(empty()) {
        return -1;
    }
    double_node *i = tail->prev;
    int ret = i->key;
    tail->prev = i->prev;
    i->prev->next = tail;
    free(i);

    return ret;
}

int size()
{
    int count = 0;
    double_node *i = head;

    while(i->next != tail) {
        i = i->next;
        count++;
    }
    return count;
}

int empty()
{
    return head->next == tail;
}

int front() //insert k
{
    if(empty()) {
        return -1;
    }
    return head->next->key;
}

int back() //insert k
{
    if(empty()) {
        return -1;
    }
    return tail->prev->key;
}

int main()
{
	init_dlist();
    int N; //TestCase
    scanf("%d", &N);

    int key;
    char cmd[11];
    while(N--) {
        scanf("%s", cmd);
        if(strcmp(cmd, "push_front") == 0) {
            scanf(" %d", &key);
            push_front(key);
        } else if(strcmp(cmd, "push_back") == 0) {
            scanf(" %d", &key);
            push_back(key);
        } else if(strcmp(cmd, "pop_front") == 0) {
            printf("%d\n",pop_front());
        } else if(strcmp(cmd, "pop_back") == 0) {
            printf("%d\n",pop_back());
        } else if(strcmp(cmd, "size") == 0) {
            printf("%d\n",size());
        } else if(strcmp(cmd, "empty") == 0) {
            printf("%d\n",empty());
        } else if(strcmp(cmd, "front") == 0) {
            printf("%d\n",front());
        } else if(strcmp(cmd, "back") == 0) {
            printf("%d\n",back());
        }
    }
	return 0;
}