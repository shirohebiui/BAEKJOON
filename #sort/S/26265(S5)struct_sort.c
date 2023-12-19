#include <stdio.h>
#include <string.h>

typedef struct duo{
    char mento[21];
    char menti[21];
}duo;

duo node[100001];

void swap(duo *s1, duo *s2) {
    duo tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
}

void qsort(int start, int end, int mod) {
    if(start >= end) return;
    int left = start;
    int right = end;
    char pivot[21];
    if(mod) {
        strcpy(pivot, node[(start+end)/2].mento);
        while(left<=right) {
            while(strcmp(node[left].mento, pivot) < 0) left++;
            while(strcmp(node[right].mento, pivot) > 0) right--;
            if(left <= right) swap(&node[left++], &node[right--]);
        }
    } else {
        strcpy(pivot, node[(start+end)/2].menti);
        while(left<=right) {
            while(strcmp(node[left].menti, pivot) > 0) left++;
            while(strcmp(node[right].menti, pivot) < 0) right--;
            if(left <= right) swap(&node[left++], &node[right--]);
        }
    }
    qsort(start, right, mod);
    qsort(left, end, mod);
}

int main() {
    //input
    int N; scanf(" %d", &N);
    for(int i=0; i<N; i++) {
        scanf(" %s %s", node[i].mento, node[i].menti);
    }

    //sort 1
    qsort(0, N-1, 1);
    //sort 2
    int start=0;
    for(int i=0; i+1<N; i++) {
        if(strcmp(node[i].mento, node[i+1].mento) != 0) {
            qsort(start, i, 0);
            start = i+1;
        }
    }
    qsort(start, N-1, 0);
    for(int i=0; i<N; i++) {
        //printf("%d : ", i);
        printf("%s %s\n", node[i].mento, node[i].menti);
    }
    return 0;
}