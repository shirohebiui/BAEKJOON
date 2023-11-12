//https://www.acmicpc.net/problem/18111
/*
위에서 내려가지말고 아래에서 올라가며 최적시간을 찾고
시간이 같으면 더 높은 높이를 선택한다.
임의의 높이 h에서 일어나는일을 잘 정리하면 되는데 h에서 일어날일과 
h-1에서 일어날일의 구분을 처음에 잘못접근해서 시간이오래걸림
*/
#include <stdio.h>
#define MAX 501
int block[MAX];
int N, M, B;
int NM, top = 257, bot = 0;
int best_time, best_high;

void input_data();

int rest() {
    int ret = 0;
    for(int i=bot; i<=top; i++) {
        ret += block[i];
    }
    return ret;
}

void working() {
    int delete = rest(); // 현bot부터 top까지 치워야할 블럭
    int insert = 0; //현bot까지 채워야할 블럭
    int time = 500*500*256; int high;
    // printf("bot %d, top %d\n", bot-1, top-1);
    for(int h = bot; h <= top+1; h++) {
        // printf("H%d B&del : %d ins : %d\n", h-1, delete, insert);
        if(B+delete >= insert) {
            int work = delete*2 + insert;
            if(work <= time) {
                time = work;
                high = h-1;
            }
        }
        insert += NM - block[h];
        delete -= block[h];
    }
    best_time = time;
    best_high = high-1; // 0-256 -> 1-257 이동
}

int main() {
    scanf("%d %d %d", &N, &M, &B);
    input_data();
    working();
    printf("%d %d\n", best_time, best_high);

    return 0;
}

void input_data() {
    int high, max = 0;
    int tmp[258] = {0, };
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            scanf(" %d", &high);
            tmp[high+1]++;
            // for(int h=1; h<=high+1; h++) //new arr만들어서 최적화
            //     block[h]++;
        }
    }
    for(int h=1; h<258; h++) {
        for(int i=1; i<=h; i++) {
            block[i] += tmp[h];
        }
    }
    NM = N*M;
    block[0] = NM;
    while(block[top] == 0) top--;
    while(block[bot] == NM) bot++;
}