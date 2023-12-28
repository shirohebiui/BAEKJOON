#include <stdio.h>
#include <string.h>

typedef struct nodes {
    int left;
    int right;
}nodes;
// 1-A 2-B ... Z-26
nodes tree[27];
void prefix(int node);
void infix(int node);
void postfix(int node);

int main() {
    int N; scanf("%d", &N);
    char p, l, r;
    for(int i=0; i<N; i++) {
        scanf(" %c %c %c", &p, &l, &r);
        int idx = p - '@';
        if(l != '.') tree[idx].left = l-'@';
        if(r != '.') tree[idx].right = r-'@';
    }
    prefix(1); printf("\n");
    infix(1); printf("\n");
    postfix(1); printf("\n");
    return 0;
}

void prefix(int node) {
    printf("%c", node+'@');
    if(tree[node].left) prefix(tree[node].left);
    if(tree[node].right) prefix(tree[node].right);
}

void infix(int node) {
    if(tree[node].left) infix(tree[node].left);
    printf("%c", node+'@');
    if(tree[node].right) infix(tree[node].right);
}

void postfix(int node) {
    if(tree[node].left) postfix(tree[node].left);
    if(tree[node].right) postfix(tree[node].right);
    printf("%c", node+'@');
}