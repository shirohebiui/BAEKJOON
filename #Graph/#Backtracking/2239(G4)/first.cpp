#include <cstdio>
#include <bitset>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); val++)

struct pos {int y, x;};
pos p[82]; int psize;

char board[9][10];
bitset<10> square[3][3], col[9], row[9];

/*
개선 가능성
1~9까지 탐색하지말고 가능한 숫자를 좁혀놓으면 빠를듯싶다.
예를 들어 (1,2)에는 3,4,5만 올수 있다면 
이를 vector를 활용해서 넣어놓고 for(auto &p : v)로
가능한 범위만 탐색하는 식으로...
*/

inline void init() {
    FOR(y, 0, 9) {
        FOR(x, 0, 9) {
            int bit = board[y][x] - '0';
            if(bit == 0) p[psize++] = {y, x};
            else {
                col[y][bit] = 1;
                row[x][bit] = 1;
                square[y/3][x/3][bit] = 1;
            }
        }
    }
}

#define now p[idx]
inline bool isValid(int idx, int b) {
    return (square[now.y/3][now.x/3][b] == 0) && (col[now.y][b] == 0) && (row[now.x][b] == 0);
}

void dfs(int idx) {
    if(idx == psize) {
        fwrite(board, sizeof(char), sizeof(board), stdout);
        exit(0);
    }
    FOR(i, 1, 10) {
        if(isValid(idx, i)) {
            //chk in
            col[now.y][i] = 1;
            row[now.x][i] = 1;
            square[now.y/3][now.x/3][i] = 1;
            board[now.y][now.x] = i + '0';

            dfs(idx+1);

            //chk out
            board[now.y][now.x] = '0';
            square[now.y/3][now.x/3][i] = 0;
            row[now.x][i] = 0;
            col[now.y][i] = 0;
        }
    }
}

int main() {
    fread(board, sizeof(char), 9*10, stdin);
    board[8][9] = '\n';
    init();
    dfs(0);
    return 0;
}