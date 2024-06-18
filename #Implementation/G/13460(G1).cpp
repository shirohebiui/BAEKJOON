#include <iostream>
#include <queue>
typedef struct pos{
    char ry, rx, by, bx, cnt; //red y,x blue y,x
}pos;

char board[10][10]; int n, m;
std::queue<pos> q;
#define right 0
#define left 1
#define up 2
#define down 3

char ry, rx, by, bx;
char vis[10][10][10][10];

pos s;
static inline void move(int arrow) {
    ry =  q.front().ry; rx =  q.front().rx;
    by =  q.front().by; bx =  q.front().bx;
    //move cnt over
    if(q.front().cnt > 9) return;

    //moving func
    switch (arrow)
    {
    case right:
        while(board[ry][rx] != 'O' && board[ry][rx+1] != '#' && (rx+1 != bx || ry != by)) rx++;
        while(board[by][bx] != 'O' && board[by][bx+1] != '#' && (bx+1 != rx || by != ry)) bx++;
        while(board[ry][rx] != 'O' && board[ry][rx+1] != '#' && (rx+1 != bx || ry != by)) rx++;
        break;
    case left:
        while(board[ry][rx] != 'O' && board[ry][rx-1] != '#' && (rx-1 != bx || ry != by)) rx--;
        while(board[by][bx] != 'O' && board[by][bx-1] != '#' && (bx-1 != rx || by != ry)) bx--;
        while(board[ry][rx] != 'O' && board[ry][rx-1] != '#' && (rx-1 != bx || ry != by)) rx--;
        break;
    case up:
        while(board[ry][rx] != 'O' && board[ry-1][rx] != '#' && (ry-1 != by || rx != bx)) ry--;
        while(board[by][bx] != 'O' && board[by-1][bx] != '#' && (by-1 != ry || bx != rx)) by--;
        while(board[ry][rx] != 'O' && board[ry-1][rx] != '#' && (ry-1 != by || rx != bx)) ry--;
        break;
    case down:
        while(board[ry][rx] != 'O' && board[ry+1][rx] != '#' && (ry+1 != by || rx != bx)) ry++;
        while(board[by][bx] != 'O' && board[by+1][bx] != '#' && (by+1 != ry || bx != rx)) by++;
        while(board[ry][rx] != 'O' && board[ry+1][rx] != '#' && (ry+1 != by || rx != bx)) ry++;
        break;
    }
    //blue in hole
    if(board[by][bx] == 'O') return;
    switch (arrow)
    {
    case right:
        if(board[by][bx+1] == 'O') return;
        break;
    case left:
        if(board[by][bx-1] == 'O') return;
        break;
    case up:
        if(board[by-1][bx] == 'O') return;
        break;
    case down:
        if(board[by+1][bx] == 'O') return;
        break;
    }
    //isVisited
    if(vis[ry][rx][by][bx]) return;
    vis[ry][rx][by][bx] = 1;


    //changed & valid
    s.by = by; s.bx = bx; s.ry = ry; s.rx = rx; s.cnt = q.front().cnt + 1;
    q.push(s);
}
void bfs() {
    while(!q.empty()) {
        // test(t);
        if(board[q.front().ry][q.front().rx] == 'O') {
            std::cout << (int)q.front().cnt << "\n";
            return;
        } else {
            move(right);
            move(left);
            move(up);
            move(down);
        }
        q.pop();
    }
    std::cout << "-1\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

    //input & init
    std::cin >> n >> m;
    for(int y=0; y<n; y++) {
        for(int x=0; x<m; x++) {
            std::cin >> board[y][x];
            if(board[y][x] == 'R') {
                board[y][x] = '.';
                s.ry = y; s.rx = x;
            } else if(board[y][x] == 'B') {
                board[y][x] = '.';
                s.by = y; s.bx = x;
            }
        }
    }
    s.cnt = 0;
    vis[s.ry][s.rx][s.by][s.bx] = 1;
    q.push(s);
    //func
    bfs();
    return 0;
}