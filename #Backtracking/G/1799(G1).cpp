#include <iostream>
using namespace std;

char board[10][10];
char vis[10][10];
int n, best;
//대충 잘... 최선의 경우 한줄이 활성화될 확률이 높아보여서 그렇게 풀었음
//한줄 활성화로 최대비숍을 놓는 경우는 최선이 아닐수있음 이 경우는 아래와 같은 예제로 반례가 존재
/*
5
0 0 1 0 0
1 0 0 0 1
0 0 0 0 0
1 0 0 0 1
0 1 1 1 0
*/
void test();
#define isSafe(y, x) (y<n && y>=0 && x<n && x>=0)

int valid(int y, int x) {
    int i = 1;
    while(y-i >= 0) {
        if(isSafe(y-i, x-i) && vis[y-i][x-i] == 1) return 0;
        if(isSafe(y-i, x+i) && vis[y-i][x+i] == 1) return 0;
        i++;
    }
    return 1;
}
void dfs(int y, int x, int cnt) {
    best = max(best, cnt);
    while(y<n) {
        for(; x<n; x++) {
            if(board[y][x] && !vis[y][x] && valid(y,x)) {
                vis[y][x] = 1;
                if(x+1 < n) dfs(y, x+1, cnt+1);
                if(y+1 < n) dfs(y+1, 0, cnt+1);
                vis[y][x] = 0;
            }
        }
        x = 0;
        y++;
    }
}

void paint(int y, int x) {
    vis[y][x] = 1;
    int i = 1;
    while(y-i >= 0) {
        if(isSafe(y-i, x-i)) vis[y-i][x-i] = 3;
        if(isSafe(y-i, x+i)) vis[y-i][x+i] = 3;
        i++;
    }
}

void func() {
    int cnt;
    for(int i=0; i<n; i++) {
        cnt = 0;
        for(int j=0; j<n; j++) {
            if(board[i][j]) {
                cnt++; paint(i, j);
            }
        }
        dfs(0,0,cnt);
        memset(vis, 0x00, sizeof(vis));
    }

    for(int i=0; i<n; i++) {
        cnt = 0;
        for(int j=0; j<n; j++) {
            if(board[j][i]) {
                cnt++; paint(j, i);
            }
        }
        dfs(0,0,cnt);
        memset(vis, 0x00, sizeof(vis));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> board[i][j];
            board[i][j] -= '0';
        }
    }
    // dfs(0,0,0);
    func();
    cout << best << "\n";
    return 0;
}
void test() {
    cout << "test\n";
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << (int)vis[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}