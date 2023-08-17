#include <stdio.h>
#include <stdlib.h>

/*
*/

void input_arr(int *arr,int wdith);

void swap(int *a, int *b);

void quick_sort(int *data, int start, int end);

void print_all_1D(int *arr, int width);

long find_max(int *arr, int width);
long find_min(int *arr, int width);

void Eratos(int *arr, int n);
int main() {
    int arr[6] = {0, };
    int arr_size;
    scanf("%d", &arr_size);

    input_arr(arr, arr_size);
    //오름차 정렬
    quick_sort(arr, 0, arr_size-1);

    //가능한 수의 최대치
    long max_num = find_max(arr, arr_size);
    //가능한 수의 최소치
    long min_num = find_min(arr, arr_size);
    printf("max : %ld\n", max_num);
    //소수의 배열을 미리 만들자.
    /* int prime[729000000]; //30^6 = 729,000,000
    Eratos(prime, 729000000 - 1); */
    //print_all_1D(arr, arr_size);

    return 0;
}

void input_arr(int *arr,int wdith) {
    for(int w = 0; w < wdith; w++) {
        scanf(" %d", &arr[w]);
    }
}

void quick_sort(int *data, int start, int end) {
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
		quick_sort(data, start, right);
	if(end > left)
		quick_sort(data, left, end);
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_all_1D(int *arr, int width) {
    for(int w = 0; w < width; w++) {
        printf("%d ", arr[w]);
    }
    printf("\n");
}


long find_max(int *arr, int width) {
    if(width > 0)
        return arr[width-1] * find_max(arr, width-1);
    else
        return 1;
}

long find_max(int *arr, int width) {
    if(width > 0)
        return arr[width-1] * find_max(arr, width-1);
    else
        return 1;
}

void Eratos(int *arr, int n) {
    int i, j;
    for(i=2; i*i<=n; i++) {
        for(j=i*i; j<=n; j+=i) {
            if(arr[i*j] == 0)   //저장하는 연산을 여러번 하지 않기위해
                arr[i*j] = 1;
        }
    }
}