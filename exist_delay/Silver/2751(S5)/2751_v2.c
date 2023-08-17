#include <stdio.h>
#define MAX 1000000
/*
N개의 수가 주어질 경우
오름차순으로 정렬
퀵소트
*/
int data[MAX] = {0,};

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quick_sort(int start, int end) {
	int left = start;
	int right = end;
    int pivot = data[ (left + right) / 2 ];
	while(left<=right) {
		while(data[left] < pivot) {
			left++;
		}
		while(data[right] > pivot) {
			right--;
		}
		if(left<=right) {
			swap(&data[left], &data[right]);
			left++;
			right--;
		}
	}

	if(start < right)
		quick_sort(start, right);
	if(end > left)
		quick_sort(left, end);
}

int main()
{
	int MAX_INPUT_COUNT;
	scanf("%d", &MAX_INPUT_COUNT);
	int loop_count = MAX_INPUT_COUNT;
	while(loop_count--){
		scanf("%d", &data[loop_count]);
	}
	quick_sort(0, MAX_INPUT_COUNT-1);
	
	loop_count = 0;
	while(loop_count < MAX_INPUT_COUNT) {
		printf("%d\n", data[loop_count++]);
	}
    return 0;
}