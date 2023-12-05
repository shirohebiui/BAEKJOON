#include <stdio.h>
#define house_max 100
#define chicken_max 13
#define INF 1e9
#define abs(n) ((n)>0?(n):-(n))
#define distance(r1, c1, r2, c2) (abs(r1 - r2) + abs(c1 - c2))
#define min(a,b) (a<b?a:b)

//std data
void input_data();
int N, M;
int chicken[chicken_max][2]; //0-y, 1-x
int house[house_max][2];
int chicken_cnt, house_cnt;

void graph_dist();
int graph[chicken_max][house_max]; //치킨집 <-> 집 거리 기록

void dfs(int idx, int depth);
int select[chicken_max];

// dfs -> 치킨집 M개를 뽑아놓고 (xCm)
// find_min -> 집마다 최선의 치킨거리를 구한다.
void find_min();
int min_dist = INF;

void test();

int main() {
    input_data();
    graph_dist();
    //test();
    dfs(0, 0);
    printf("%d\n", min_dist);
    return 0;
}

void input_data() {
    scanf("%d %d", &N, &M);
    int input;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf(" %d", &input);
            if(input == 1) {
                house[house_cnt][0] = i;
                house[house_cnt][1] = j;
                house_cnt++;
            }
            if (input == 2) {
                chicken[chicken_cnt][0] = i;
                chicken[chicken_cnt][1] = j;
                chicken_cnt++;
            }
        }
    }
}
void graph_dist() {
    for(int i=0; i<chicken_cnt; i++) {
        for(int j=0; j<house_cnt; j++) {
            graph[i][j] = abs(distance(chicken[i][0], chicken[i][1], house[j][0], house[j][1]));
        }
    }
}

void dfs(int idx, int depth) {
    if(depth == M) {
        find_min();
        return;
    }
    for(int i=idx; i<chicken_cnt; i++) {
        if(select[i] == 0) {
            select[i] = 1;
            dfs(i, depth+1);
            select[i] = 0;
        }
    }
}

void find_min() {
    int tmp = 0;
    int find = 0;
    for(int i=0; i<house_cnt; i++) {
        tmp = INF;
        for(int j=0; j<chicken_cnt; j++) {
            if(select[j]) {
                tmp = min(tmp, graph[j][i]);
            }
        }
        find += tmp;
        if(find >= min_dist) return; //더이상 연산 무용
    }
    min_dist = find;
}

void test() {
    printf("chicken cnt : %d, house cnt : %d\n", chicken_cnt, house_cnt);
    for(int i=0; i<chicken_cnt; i++) {
        printf("%d : ", i);
        for(int j=0; j<house_cnt; j++) {
            printf(" %d", graph[i][j]);
        }
        printf("\n");
    }
    // 거리 연산 검증
    // printf("chicken\n");
    // for(int i=0; i<chicken_cnt; i++) {
    //     printf("%d, %d\n", chicken[i][0], chicken[i][1]);
    // }
    // printf("house\n");
    // for(int i=0; i<house_cnt; i++) {
    //     printf("%d, %d\n", house[i][0], house[i][1]);
    // }
    // for(int i=0; i<chicken_cnt; i++) {
    //     for(int j=0; j<house_cnt; j++) {
    //         printf("abs(%d-%d) + abs(%d-%d) = %d\n",
    //         chicken[i][0],  house[j][0], chicken[i][1], house[j][1], graph[i][j]);
    //     }
    //     printf("\n");
    // }
}
