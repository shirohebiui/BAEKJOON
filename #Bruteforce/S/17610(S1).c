#include <stdio.h>
#define abs(n) ((n)>0?(n):-(n))

void input();
int num[13], cnt;
char visited[13];

int queue[13][10000], rear[13];
char arr[200000*13];
int std;
int max;

void find_nCr();
void dfs(int idx, int select, int R, int sum);
void tmp_dfs(int idx, int select, int R, int sum);
void check_sum();
void answer();
void test();

int main() {
    input();     //입력받고
    find_nCr();  //nCr 생성
    check_sum(); //nCr 끼리 계산
    answer();    //정답!
    //test();
    return 0;
}

void input() {
    scanf("%d", &cnt);
    for(int i=0; i<cnt; i++) {
        scanf(" %d", &num[i]);
        max += num[i];
    }
}

void find_nCr() {
    for(int i=0; i<=cnt/2; i++) {
        dfs(0, 0, i, 0); //nCi
    }
}

void dfs(int idx, int select, int R, int sum) {
    if(select == R) {
        std = sum;
        for(int i=1; i<=cnt-R; i++)
            tmp_dfs(0,0,i, 0);
        return;
    }
    for(int i=idx; i<cnt; i++) {
        if(visited[i] == 0) {
            visited[i] = 1;
            dfs(i, select+1, R, sum + num[i]);
            visited[i] = 0;
        }
    }
}

void tmp_dfs(int idx, int select, int R, int sum) {
    if(select == R) {
        // printf("%d %d :", std, sum);
        // printf("%d %d\n", std+sum, abs(std-sum));
        arr[abs(std-sum)] = 1;
        arr[std+sum] = 1;
        return;
    }
    for(int i=idx; i<cnt; i++) {
        if(visited[i] == 0) {
            visited[i] = 1;
            tmp_dfs(i, select+1, R, sum + num[i]);
            visited[i] = 0;
        }
    }
}

void answer() {
    //printf("answer : ");
    int find_case = 0;
    for(int i=1; i<=max; i++) {
        if(arr[i] == 0) find_case++; //printf("%d ", i);
    }
    printf("%d\n", find_case);
}

void test() {
    printf("queue\n");
    for(int i=1; i<=cnt; i++) {
        printf("n C %d : ", i);
        for(int j=0; j<rear[i]; j++) {
            printf("%d ", queue[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}