#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int least_wegith = N;
    int w_3kg = 3, count_of_3kg = 0;
    int w_5kg = 5,  count_of_5kg = 0;

    count_of_5kg = least_wegith / w_5kg;
    least_wegith -= count_of_5kg * w_5kg;

    if(N%5 == 0) {
        printf("%d\n", count_of_5kg);
        return 0;
    }

    while(1) {
        if(least_wegith % w_3kg == 0) {
            count_of_3kg = least_wegith / w_3kg;
            printf("%d\n", count_of_5kg + count_of_3kg);
            return 0;
        }
        count_of_5kg--;
        least_wegith += w_5kg;
        if(least_wegith > N) {
            break;
        }
    }
    printf("-1\n");
    return 0;
}