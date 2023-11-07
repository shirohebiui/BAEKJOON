#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100001
typedef struct _member{
    int age;
    char name[101];
} member;

member data[MAX_SIZE];
member tmp[MAX_SIZE];

void merge(member *data, int left, int mid, int right) {
    int i = left, j = mid+1;
    int now = left;
    while(i <= mid && j <= right) {
        if(data[i].age <= data[j].age) {
            tmp[now] = data[i++];
        } else {
            tmp[now] = data[j++];
        }
        now++;
    }
    while(i<=mid) {
        tmp[now++] = data[i++];
    }
    while(j<=right) {
        tmp[now++] = data[j++];
    }
    memmove(&data[left], &tmp[left], sizeof(member)*(right - left + 1));
}

void merge_sort(member *data, int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        //printf("%d %d %d\n", left, mid, right);
        merge_sort(data, left, mid);
        merge_sort(data, mid+1, right);
        merge(data, left, mid, right);
    }
}
int main()
{
    int N; scanf("%d", &N); // TestCase
    int age;
    char name[101];
    for(int i=0; i<N; i++) {
        scanf("%d %s", &data[i].age, data[i].name);
    }
    merge_sort(data, 0, N-1);
    for(int i=0; i<N; i++) {
        printf("%d %s\n", data[i].age, data[i].name);
    }
	return 0;
}