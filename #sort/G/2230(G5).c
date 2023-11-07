#include <stdio.h>
typedef long type;
void swap(type *a, type *b) {
    type tmp = *a;
    *a = *b;
    *b = tmp;
}

void quick_sort(type *data, type start, type end) {
	type left = start;
	type right = end;
    type pivot = data[ (left + right) / 2 ];
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
		quick_sort(data, start, right);
	if(end > left)
		quick_sort(data, left, end);
}
int main() {
	long N, M;
	long A[100001] = {0, };
	scanf("%ld %ld", &N, &M);
	for(int i=0; i<N; i++) {
		scanf("%ld", &A[i]);
	}
	quick_sort(A, 0, N-1);
	// 정렬 완료

	// M탐색
	long gap = 2e9;
	long tmp;
	int i, j;
	for(i=0; i<N; i++) {
		j = N-1;
		while(A[i] + M < A[j]) {
			j/=2;
		}
		while(A[i] + M > A[j]) {
			j++;
		}

		if(A[j] - A[i] >= M) {
			gap = gap > A[j] - A[i] ? A[j] - A[i] : gap;
		}
	}
	printf("%ld\n", gap);
	return 0;
}