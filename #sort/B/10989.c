#include <stdio.h>

int data[10001];
void input_data(int N) {
    while(N--) {
        int num; scanf("%d", &num);
        data[num]++;
    }
}

void print_data(int N) {
    for(int i=1; i<=10000; i++) {
        while(data[i]--)
            printf("%d\n", i);
    }
}

int main() {
    unsigned int N; scanf("%d", &N);
    input_data(N);
    print_data(N);
    return 0;
}