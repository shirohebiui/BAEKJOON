#include <iostream>
#include <vector>
typedef struct pos {
    char y, x, air;
}pos;

#define SIZE 100
char board[SIZE][SIZE]; int n, m;
pos state[SIZE][SIZE];
#define AIR '0'
#define CHEESE '1'

char dy[4] = {0,1,-1,0};
char dx[4] = {1,0,0,-1};

char vis[SIZE][SIZE];
bool isSafe(int y, int x) {
    return y>=0 && y<SIZE && x>=0 && x<SIZE;
}
int py, px;
void init_out(int y, int x) {
    if(board[y][x] == CHEESE) {
        state[y][x].air++;
        return;
    }
    if(vis[y][x]) return;
    vis[y][x] = 1;
    for(int i=0; i<4; i++) {
        py = y+dy[i]; px = x+dx[i];
        if(isSafe(py, px)) {
            init_out(py, px);
        }
    }
}

void chk_out(int y, int x) {
    if(board[y][x] == CHEESE) {
        state[y][x].air++;
        return;
    }
    if(vis[y][x]) return;
    vis[y][x] = 1;
    for(int i=0; i<4; i++) {
        chk_out(y+dy[i], x+dx[i]);
    }
}
std::vector<pos *> v;
std::vector<pos *> melt;

int melting() {
    int time = 0;
    while(!v.empty()) {
        // test();
        int cnt = v.size();
        for(int i=0; i<cnt; i++) {
            if(v[i]->air >= 2) {
                melt.push_back(v[i]);
                v.erase(v.begin() + i);
                i--;
                cnt--;
            }
        }
        while(!melt.empty()) {
            py = melt.back()->y; px = melt.back()->x;
            board[py][px] = AIR;
            chk_out(py, px);
            melt.pop_back();
        }
        time++;
    }
    return time;
}

int main() {
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
    std::cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            std::cin >> board[i][j];
            if(board[i][j] == CHEESE) {
                state[i][j].y = i; state[i][j].x = j;
                v.push_back(&state[i][j]);
            }
        }
    }
    init_out(0,0);
    std::cout << melting() << "\n";
    return 0;
}