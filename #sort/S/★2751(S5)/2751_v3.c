#include <stdio.h>
#define MAX_SIZE 1000000
/*
N개의 수가 주어질 경우
오름차순으로 정렬
퀵소트
*/
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void merge(int *data, int p, int q, int r) {
	int i = p, j = q+1, k = p;
	int tmp[MAX_SIZE];
	while(i<=q && j<=r) {
		if(data[i] <= data[j]) {
			tmp[k++] = data[i++];
		} else {
			tmp[k++] = data[j++];
		}
	}
	while(i<=q) tmp[k++] = data[i++];
    while(j<=r) tmp[k++] = data[j++];
	for(int a = p; a<=r; a++) data[a] = tmp[a];
}

void merge_sort(int *data, int p, int r) {
	if(p<r) {
		int q = (p+r)/2;
		merge_sort(data, p, q);
		merge_sort(data, q+1, r);
		merge(data, p, q, r);
	}
}



void aray_print_type_of_int(int *arr,int MAX) {
	for(int i=0; i < MAX; i++) {
		printf("%d\n", arr[i]);
	}
}

int main()
{
	int data[MAX_SIZE] = {0, };
	int ROUND_OF_MAX;
	scanf("%d", &ROUND_OF_MAX);
	for(int i = 0; i < ROUND_OF_MAX; i++) {
		scanf("%d", &data[i]);
	}
	merge_sort(data, 0, ROUND_OF_MAX-1);
	aray_print_type_of_int(data, ROUND_OF_MAX);
    return 0;
}