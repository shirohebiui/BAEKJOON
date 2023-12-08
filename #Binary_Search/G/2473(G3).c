#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5000
#define abs(n) (n>0?n:-n)

long queue[MAX_SIZE]; int rear; //세 용액
long best[3];

void swap(long *a, long *b);
void quick_sort(long *data, long start, long end);

void input_data();

void find_best() {
    long gap = 3e10+1;
    long cur;
    int left, right;
    for(int i=0; i<rear; i++) {
        left = i+1; right = rear-1;
        while(left < right) {
            cur =  queue[i] + queue[left] + queue[right];
            if(abs(cur) < gap) {
                gap = abs(cur);
                best[0] = queue[i];
                best[1] = queue[left];
                best[2] = queue[right];
            }
            if(cur < 0) left++;
            else        right--;
        }
    }
}

int main() {
    input_data();
    quick_sort(queue, 0, rear-1);
    find_best();
    printf("%ld %ld %ld\n", best[0], best[1], best[2]);
    return 0;
}

void swap(long *a, long *b) {
    long tmp = *a;
    *a = *b;
    *b = tmp;
}
void quick_sort(long *data, long start, long end) {
	if(start >= end) return;
	long left = start;
	long right = end;
    long pivot = data[ (left + right) / 2 ];
	while(left<=right) {
		while(data[left] < pivot) left++;
		while(data[right] > pivot) right--;
		if(left<=right) {
			swap(&data[left], &data[right]);
			left++; right--;
		}
	}
	quick_sort(data, start, right);
	quick_sort(data, left, end);
}

void input_data() {
    int N; scanf(" %d", &N);
    while(N--) {
        scanf("%ld", &queue[rear++]);
    }
}
