#include <stdio.h>
#include <stdlib.h>
#define MAX 100001
//https://www.acmicpc.net/problem/11650
//i+1이 N일 경우에 대해 조건을 제대로 못처리함
int pos_x[MAX] = {0, };
int pos_y[MAX] = {0, };

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quick_sort_pos_x(int start, int end) {
	int left = start;
	int right = end;
    int pivot = pos_x[ (left + right) / 2 ];
	while(left<=right) {
		while(pos_x[left] < pivot) {
			left++;
		}
		while(pos_x[right] > pivot) {
			right--;
		}
		if(left<=right) {
			swap(&pos_x[left], &pos_x[right]);
			swap(&pos_y[left], &pos_y[right]);
			left++;
			right--;
		}
	}

	if(start < right)
		quick_sort_pos_x(start, right);
	if(end > left)
		quick_sort_pos_x(left, end);
}

void quick_sort_pos_y(int start, int end) {
	int left = start;
	int right = end;
    int pivot = pos_y[ (left + right) / 2 ];
	while(left<=right) {
		while(pos_y[left] < pivot) {
			left++;
		}
		while(pos_y[right] > pivot) {
			right--;
		}
		if(left<=right) {
			swap(&pos_x[left], &pos_x[right]);
			swap(&pos_y[left], &pos_y[right]);
			left++;
			right--;
		}
	}

	if(start < right)
		quick_sort_pos_y(start, right);
	if(end > left)
		quick_sort_pos_y(left, end);
}

int main()
{
    int N;
    scanf("%d", &N);

    //입력
    int i;
    for(i=0; i<N; i++) {
        scanf("%d %d", &pos_x[i], &pos_y[i]);
    }

    //정렬 X
    quick_sort_pos_x(0, N-1);

    //정렬 Y
    int start = 0;
    int end;

    i=0;
    while(1) {
		if(i+1 == N) {
			quick_sort_pos_y(start, N-1);
			break;
		} else if(pos_x[i] != pos_x[i+1]) {
            end = i;
            //printf("start : %d, end : %d\n", start, end);
            quick_sort_pos_y(start, end);
            start = i+1;
        }
        i++;
    }

    //출력
    for(i=0; i<N; i++) {
        printf("%d %d\n", pos_x[i], pos_y[i]);
    }
    return 0;
}