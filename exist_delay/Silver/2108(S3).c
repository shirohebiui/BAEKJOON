#include <stdio.h>
/*
최빈값을 구할때
서순을 다시한번 생각해서 고쳤고

중앙값을 구할때
정수의 범위가 -4000~4000인데 디폴트를 0으로 잡아서 예외케이스가 생겼다.
9999으로 디폴트를 바꿔서 해결
*/
int data[8001] = {0, };
int N, rear;

int main() {
    scanf("%d", &N);
    rear = N;
    int val;
    while(N--) {
        scanf(" %d", &val);
        data[val+4000]++;
    }

    int min = 4000, max = -4000;
    int center = 9999;
    int frequency = 0, fq_val[2] = {9999, 9999};
    float tmp = 0;
    int sum = 0;
    for(int i=0, count=0; i<=8000 && count<rear; i++) {
        if(data[i] != 0) {
            int num = i-4000;
            count+=data[i];
            //printf("count %d\n", count);

            //산술평균
            sum += num * data[i];

            //중앙값
            if(count > rear/2 && center == 9999) {
                center = num;
            }

            //최빈값
            if(data[i] > frequency) {
                frequency = data[i];
                fq_val[0] = num;
                fq_val[1] = num;
            }
            if(data[i] == frequency) {
                if(fq_val[0] > num) {
                    fq_val[1] = fq_val[0];
                    fq_val[0] = num;
                } else if(fq_val[0] == fq_val[1]) {
                    fq_val[1] = num;
                } else {
                    fq_val[1] = num > fq_val[1] ? fq_val[1] : num;
                }
            }
            //printf("fq : %d %d\n", fq_val[0], fq_val[1]);

            //범위
            min = num<min ? num : min;
            max = num>max ? num : max;
        }
    }
    //printf("%d", sum);
    tmp = (float)sum / rear;
    //printf("%f", tmp);
    if(tmp > 0)
        tmp += 0.5;
    if(tmp < 0)
        tmp -= 0.5;
    sum = tmp;

    //printf("산술 :");
    printf("%d\n", sum);
    //printf("중앙 :");
    printf("%d\n", center);
    //printf("최빈 :");
    printf("%d\n", fq_val[1]);
    //printf("범위 :");
    printf("%d\n", max-min);


    return 0;
}