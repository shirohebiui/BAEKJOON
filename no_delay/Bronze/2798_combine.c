#include <stdio.h>
#define MAX 100001

int card[MAX];
int sum_of_card[MAX*3] = {0, };
int max_sum = 0;

void input_card(int max_of_card) {
    for(int i=0; i<max_of_card; i++) {
        scanf("%d", &card[i]);
    }
}

void combine_N(int rear, int one, int two, int thr) {
    if(one != -1 && two != -1 && thr != -1) {
        sum_of_card[card[one]+card[two]+card[thr]] = 1;
        max_sum = max_sum > card[one]+card[two]+card[thr] ? max_sum : card[one]+card[two]+card[thr];
    } 
    for(int i=0; i<rear; i++) {
        if(one == -1) {
            combine_N(rear, i, two, thr);
        } else if(i != one) {
            if(two == -1) {
                combine_N(rear, one, i, thr);
            } else if(i != two) {
                if(thr == -1) {
                    combine_N(rear, one, two, i);
                }
            }
        }
    }
}

int find_most_adjacent_value(int goal) {
    for(int i=goal; i>=3; i--) {
        if(sum_of_card[i] == 1) {
            return i;
        }
    }
    return 0;
}

void test_print(int rear) {
    printf("max = %d\n", max_sum);
    for(int i=1; i<=max_sum; i++) {
        printf("%d ", sum_of_card[i]);
    }
    printf("\n");
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    input_card(N);
    combine_N(N, -1, -1, -1);
    //test_print(N);
    printf("%d\n", find_most_adjacent_value(M));
    return 0;
}