#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)
#define isSafe(now) (now.y < n && now.y >= 0 && now.x < m && now.x >=0)


#define BSIZE 2000 //board size
char board[BSIZE][BSIZE]; int n, m;
char vis[BSIZE][BSIZE][4]; int cnt;

struct pos {int y,x;};

#define left 0
#define up 1
#define right 2
#define down 3
void next_pos(pos *s, int dir) {
    switch (dir)
    {
    case left:
        --(s->x); return;
    case right:
        ++(s->x); return;
    case up:
        --(s->y); return;
    case down:
        ++(s->y); return;

    default:
        cout << "error\n"; return;
    }
}

#define blank '0'
#define NtoS_pass '1'
#define EtoW_pass '2'
#define NtoE_pass '3'
#define NtoW_pass '4'
#define wind_generator '9'
void change_dir(pos t, int *dir) {
    switch (board[t.y][t.x])
    {
    case blank:
        return;
    case wind_generator:
        return;
    case EtoW_pass:
        if(*dir == left || *dir == right) return;
        *dir = -1; return;
    case NtoS_pass:
        if(*dir == up || *dir == down) return;
        *dir = -1; return;
    case NtoE_pass:
        if(*dir == right)     *dir = up;
        else if(*dir == down) *dir = left;
        else if(*dir == up)   *dir = right;
        else if(*dir == left) *dir = down;
        return;
    case NtoW_pass:
        if(*dir == right)      *dir = down;
        else if(*dir == up)    *dir = left;
        else if(*dir == down)  *dir = right;
        else if(*dir == left)  *dir = up;
        return;
    default:
        cout << "change error\n";
        return;
    }
}
void wind_moving(pos now, int dir) {
    // next_pos(&now, dir);
    while(isSafe(now)) {
        if(vis[now.y][now.x][dir]) return;
        vis[now.y][now.x][dir] = 1;
        // cout << now.y << ", " << now.x << "\n";
        change_dir(now, &dir);
        if(dir == -1) return;
        next_pos(&now, dir);
    }
}


#include <queue>
queue<pos> wind_gen;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //input
    cin >> n >> m;
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            cin >> board[i][j];
            if(board[i][j] == wind_generator) {
                wind_gen.push({i, j});
            }
        }
    }

    //func
    while(!wind_gen.empty()) {
        pos now = wind_gen.front(); wind_gen.pop();
        FOR(dir, 0, 4) {
            wind_moving(now, dir);
        }
    }
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            FOR(k, 0, 4) {
                if(vis[i][j][k]) {++cnt; break;}
            }
        }
    }

    //answer
    cout << cnt << "\n";
    return 0;
}