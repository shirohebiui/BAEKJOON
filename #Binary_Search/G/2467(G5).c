#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100001
//https://www.acmicpc.net/problem/2470

long queue[MAX_SIZE];
int rear;
long result[2];

long abs_(long n) {
    if(n > 0) {
        return n;
    }
    return n * -1;
}

void swap(long *a, long *b) {
    long tmp = *a;
    *a = *b;
    *b = tmp;
}

void quick_sort(long *data, long start, long end) {
	long left = start;
	long right = end;
    long pivot = data[(left + right)/2];
	while(left<=right) {
		while(abs_(data[left]) < abs_(pivot)) {
			left++;
		}
		while(abs_(data[right]) > abs_(pivot)) {
			right--;
		}
		if(left<=right) {
			swap(&data[left], &data[right]);
			left++;
			right--;
		}
	}

	if(start < right)
		quick_sort(data, start, right);
	if(end > left)
		quick_sort(data, left, end);
}


void find_gap_aq() {
    long gap = 2000000002;
    int i = 0;
    while(i++ < rear-1) {
        if(gap > abs_(queue[i] + queue[i-1])) {
            gap = abs_(queue[i] + queue[i-1]);
            result[0] = queue[i];
            result[1] = queue[i-1];
        }
    }
}

int main() {
    //input test case
    int N;
    scanf("%d", &N);

    //input data
    long num;
    for(int i=0; i<N; i++) {
        scanf("%ld", &num);
        queue[rear++] = num;
    }

    //sort data
    quick_sort(queue, 0, rear-1);
    // for(int i=0; i<rear; i++)
    //     printf("%ld ", queue[i]);
    // printf("\n");

    //func
    find_gap_aq();
    if(result[0] < result[1])
        printf("%ld %ld\n", result[0], result[1]);
    else
        printf("%ld %ld\n", result[1], result[0]);

    return 0;
}


