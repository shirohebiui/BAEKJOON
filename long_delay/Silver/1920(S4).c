#include <stdio.h>

long data[100000] = {0, };
int flag = 1;
void swap(long *a, long *b) {
    long tmp = *a;
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

void search(int k, int left, int right) {
    int mid = (left+right)/2;
    int pivot = data[mid];
    if(left <= right && flag) {
        if(pivot == k) {
            flag = 0;
        } else if(k < pivot) {
            search(k, left, mid-1);
        } else if(k > pivot) {
            search(k, mid+1, right);
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    int rear = N-1;
    while(N--) {
        scanf(" %ld", &data[N]);
    }
    quick_sort(0, rear);

    int M;
    scanf("%d", &M);
    while(M--) {
        flag = 1;
        int k;
        scanf(" %d", &k);
        search(k, 0, rear);
        if(flag == 0) {
            //printf("%d : ", k);
            printf("1\n");
        } else {
            //printf("%d : ", k);
            printf("0\n");
        }
    }
    //printf("pass\n");
    return 0;
}