#include <iostream>
using namespace std;

#include <queue>
#include <cstring>
int Vcnt;
char std_board[52][52];
char board[52][52]; 
#define WALL 0
#define VIRUS 2
#define EMPTY 1
int space, n, m, best = 9999;

typedef struct pos{
    int y, x;
}pos;
pos virus[10], s[10];
queue <pos> q;

char dy[4] = {0,0,-1,1};
char dx[4] = {1,-1,0,0};
void simul() {
    int infect = 0, time = 0, py, px;
    pos now;
    if(space == 0) {
        best = 0;
        return;
    }
    time++;
    while(!q.empty()) {
        int round = q.size();
        while(round--) {
            now = q.front(); q.pop();
            for(int i=0; i<4; i++) {
                py = now.y + dy[i];
                px = now.x + dx[i];
                if(board[py][px] != WALL) {
                    q.push({py, px});
                    if(board[py][px] == EMPTY) infect++;
                    board[py][px] = WALL;
                }
            }
        }
        if(infect == space) {
            best = min(best, time);
            while(!q.empty()) q.pop();
            return;
        }
        time++;
    }
}

void dfs(int idx, int chk) {
    if(chk == m) {
        memmove(board, std_board, sizeof(board));
        for(int i=0; i<m; i++) q.push(s[i]);
        simul();
        return;
    }
    for(int i=idx; i<Vcnt; i++) {
        s[chk] = virus[i];
        dfs(i+1, chk+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<=n+1; i++) {
        std_board[i][0]   = WALL;
        std_board[i][n+1] = WALL;
        std_board[0][i]   = WALL;
        std_board[n+1][i] = WALL;
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int input; cin >> input;
            if(input == 1) {
                std_board[i][j] = WALL;
            } else if(input == 2) {
                std_board[i][j] = VIRUS;
                virus[Vcnt].y = i; virus[Vcnt].x = j;
                Vcnt++;
            } else {
                std_board[i][j] = EMPTY;
                space++;
            }
        }
    }
    dfs(0,0);
    if(best >= 9999) cout << "-1\n";
    else cout << best << "\n";
    return 0;
}