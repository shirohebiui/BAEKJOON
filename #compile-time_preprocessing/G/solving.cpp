#include <cstdio>
#include <bitset>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); val++)

char board[9][10];
bitset<10> square[3][3], col[9], row[9];

struct pos {int y, x;};
pos p[81]; int psize;
int arr[9][9][10];
#define now p[idx]
#define isValid(y, x, b) (square[y/3][x/3][b] == 0) && (col[y][b] == 0) && (row[x][b] == 0)

inline void init() {
    FOR(y, 0, 9) {
        FOR(x, 0, 9) {
            int bit = board[y][x] - '0';
            if(bit == 0) {
                p[psize++] = {y, x};
            } else {
                col[y][bit] = 1;
                row[x][bit] = 1;
                square[y/3][x/3][bit] = 1;
            }
        }
    }
    FOR(idx, 0, psize) {
        FOR(b, 1, 10) {
            if(isValid(now.y, now.x, b)) {
                arr[now.y][now.x][++arr[now.y][now.x][0]] = b;
            }
        }
    }
}


void dfs(int idx) {
    if(idx == psize) {
        fwrite(board, sizeof(char), sizeof(board), stdout);
        exit(0);
    }
    FOR(t, 1, arr[now.y][now.x][0]+1) {
        int i = arr[now.y][now.x][t];
        if(isValid(now.y, now.x, i)) {
            col[now.y][i] = 1;
            row[now.x][i] = 1;
            square[now.y/3][now.x/3][i] = 1;
            board[now.y][now.x] = i + '0';
            dfs(idx+1);
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