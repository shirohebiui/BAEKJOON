#include <iostream>
using namespace std;

#define FOR(val, start, end) for(int val=(start); val<=(end); ++val)

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
char dy[4] = {-1, 0, 1, 0};
char dx[4] = {0, 1, 0, -1};
int arrow;
struct pos{
    int x, y;
};
pos now;

char board[50][50]; int n, m;
int clean_cnt;
#define WALL 1
#define CLEAN 2
#define NOT_CLEAN 0
void test();
// 사방위 확인
int CHK_EWSN() {
    FOR(i,0,3) {
        if(board[now.y + dy[i]][now.x + dx[i]] == NOT_CLEAN) return 1;
    }
    return 0;
}

// 작동 함수
void excute() {
    while(1) {
        // test();
        if(board[now.y][now.x] == NOT_CLEAN) {
            board[now.y][now.x] = CLEAN;
            ++clean_cnt;
        }
        if(CHK_EWSN()) { //현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
            do {
                arrow = (arrow+3)%4; //반시계 90도 회전
            } while(board[now.y + dy[arrow]][now.x + dx[arrow]] != NOT_CLEAN);
            now.y += dy[arrow]; now.x += dx[arrow]; //전진
        } else { //재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
            now.y += dy[(arrow+2)%4]; now.x += dx[(arrow+2)%4]; //후진
            if(board[now.y][now.x] == WALL) return; //escape
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //input
    cin >> n >> m;
    cin >> now.y >> now.x >> arrow;
    FOR(i, 0, n-1) FOR(j, 0, m-1) {int input; cin >> input; board[i][j] = input;}

    //func
    excute();
    cout << clean_cnt << "\n";
    return 0;
}

void test() {
    cout << "test\n";
    FOR(i, 0, n-1) {
        FOR(j, 0, m-1) cout << (int)board[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}