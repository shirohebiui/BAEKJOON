#include <stdio.h>

int entire_case = 0;

int count_of_method_case(int now, int goal_num) {
    if(now == goal_num) {
        entire_case++;
        return 0;
    }
    if(now+1 <= goal_num) {
        count_of_method_case(now+1, goal_num);
    }
    if(now+2 <= goal_num) {
        count_of_method_case(now+2, goal_num);
    }
    if(now+3 <= goal_num) {
        count_of_method_case(now+3, goal_num);
    }
    return 0;
}

int main() {
    int T;
    scanf("%d", &T);
    
    while(T--) {
        int N;
        scanf("%d", &N);
        entire_case = 0;
        count_of_method_case(0, N);
        printf("%d\n", entire_case);
    }
    return 0;
}