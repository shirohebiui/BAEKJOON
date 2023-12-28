#include <stdio.h>

char tree[1050000];
int contact(int node);

int main() {
    int N, Q; scanf("%d %d", &N, &Q);
    for(int i=0; i<Q; i++) {
        int node; scanf(" %d", &node);
        printf("%d\n", contact(node));
    }
    return 0;
}
int contact(int node) {
    int visited = 0;
    int want = node;
    while(node > 0) {
        if(tree[node]) {
            visited = node;
        }
        node /= 2;
    }
    if(visited == 0)
        tree[want] = 1;
    return visited;
}