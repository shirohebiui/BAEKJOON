#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

struct pos {int y,x;};
#include <vector>
vector<pos> v; //cheese
vector<pos> del; //del cheese

#define MAX_SIZE 102
#define EMPTY '0'
#define CHEESE '1'
#define AIR 'A'
//using range 1~n, 1~m
char board[MAX_SIZE][MAX_SIZE]; int n, m;
char vis[MAX_SIZE][MAX_SIZE]; 
void init_vis() {
    vis[0][m+1] = vis[n+1][m+1] = vis[n+1][0] = vis[0][0] = 1;
    FOR(y, 0, n+1) {
        vis[y][0] = 1;
        vis[y][m+1] = 1;
    }
    FOR(x, 0, m+1) {
        vis[0][x] = 1;
        vis[n+1][x] = 1;
    }
}

char dy[4] = {-1, 0, 1, 0};
char dx[4] = {0, 1, 0, -1};
int py, px;
int cheese_now, cheese_past;
void dfs(int y, int x) {
    //check air & v.push outline cheeses
    FOR(i, 0, 4) {
        py = y+dy[i]; px = x+dx[i];
        if(!vis[py][px]) {
            vis[py][px] = 1;
            if(board[py][px] == EMPTY) {
                board[py][px] = AIR;
                dfs(py, px);
            } else if(board[py][px] == CHEESE) {
                ++cheese_now;
                v.push_back({py, px});
            }
        }
    }
}

void melting() {
    cheese_past = cheese_now;
    cheese_now = 0;
    copy(v.begin(), v.end(), back_inserter(del));
    v.clear();
    for(const auto& p:del) {
        board[p.y][p.x] = AIR;
        dfs(p.y, p.x);
    }
    del.clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //input
    cin >> n >> m;
    FOR(i, 1, n+1)
        FOR(j, 1, m+1)
            cin >> board[i][j];
    //init
    init_vis();
    dfs(1,1); //init air & queuing outside cheese

    //func
    int melting_time = 0;
    while(cheese_now) {
        melting();
        ++melting_time;
    }
    cout << melting_time << "\n" << cheese_past << "\n";
    return 0;
}