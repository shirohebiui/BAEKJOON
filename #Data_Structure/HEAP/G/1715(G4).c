#include <stdio.h>
#define MAX 1000001

long heap[MAX];
int size;

void push(int key) {
    int node = ++size;
    while(node != 1 && key < heap[node/2]) {
        heap[node] = heap[node/2]; //exchange
        node /= 2;
    }
    heap[node] = key;
}

long delete_min() {
    if(size == 0)
        return 0;
    int parent, child;
    long ret = heap[1];
    long tmp = heap[size--];
    parent = 1;
    child = 2;

    while(child <= size) {
        if(child < size && heap[child] > heap[child+1]) {
            child++;
        }
        if(tmp < heap[child]) {
            break;
        }
        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }

    heap[parent] = tmp;
    //printf("ret %ld\n", ret);
    return ret;
}

int main() {
    //Test Case
    int N;
    scanf("%d", &N);

    long X;
    while(N--) {
        scanf("%ld", &X);
            push(X);
    }

    if(size == 1) {
        printf("0\n");
        return 0;
    }

    long long tmp;
    long long result = 0;
    while(size > 1) {
        tmp = delete_min() + delete_min();
        push(tmp);
        result += tmp;
    }

    printf("%lld\n", result);
    return 0;
}