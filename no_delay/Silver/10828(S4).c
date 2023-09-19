#include <stdio.h>
#include <string.h>
#define MAX 100001

int rear=0;
int stack[MAX];

void push(int data) {
	stack[rear++] = data;
}

void pop() {
	if(rear > 0) {
		rear--;
		printf("%d\n", stack[rear]);
	} else {
		printf("-1\n");
	}
}

void size() {
	printf("%d\n", rear);
}

void empty() {
	if(rear > 0) {
		printf("0\n");
	} else {
		printf("1\n");
	}
}

void top() {
	if(rear > 0)
		printf("%d\n", stack[rear-1]);
	else {
		printf("-1\n");
	}
}

int main() {
	int N;
	scanf("%d", &N);

	while(N--) {
		char cmd[10];
		int data;
		scanf(" %s", cmd);
		if(strcmp(cmd, "push") == 0) {
			scanf(" %d", &data);
			push(data);
		} else if(strcmp(cmd, "pop") == 0) {
			pop();
		} else if(strcmp(cmd, "size") == 0) {
			size();
		} else if(strcmp(cmd, "empty") == 0) {
			empty();
		} else if(strcmp(cmd, "top") == 0) {
			top();
		} else {
			printf("error\n");
			return 1;
		}
	}
	return 0;
}