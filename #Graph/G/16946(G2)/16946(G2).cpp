#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); val++)
#define FAST_IO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

#define MAX_SIZE 1002
int n, m;
char vis[MAX_SIZE][MAX_SIZE];
char *same_space[MAX_SIZE][MAX_SIZE];
void init_vis() {
    int mm = m+1, nn = n+1;
    vis[0][mm] = vis[nn][mm] = vis[nn][0] = vis[0][0] = 1;
    for(int i=1; i<nn; ++i) vis[i][0] = vis[i][mm] = 1;
    for(int i=1; i<mm; ++i) vis[0][i] = vis[nn][i] = 1;
}
char dy[4] = {-1, 0, 1, 0};
char dx[4] = {0, 1, 0, -1};

//setting : cnt of same space
short pos[MAX_SIZE*MAX_SIZE][2], py, px;
void bfs(int y, int x) {
    char *root = same_space[y][x] = &vis[y][x];
    vis[y][x] = 1; 
    int front = 0, rear = 1, mv = 1;
    pos[0][0] = y; pos[0][1] = x;
    while(front < rear) {
        FOR(i, 0, 4) {
            py = pos[front][0]+dy[i], px = pos[front][1]+dx[i];
            if(vis[py][px]) continue;
            vis[py][px] = 1;
            same_space[py][px] = root;
            pos[rear][0] = py, pos[rear][1] = px; rear++;
            mv++;
        }
        front++;
    }
    vis[y][x] = mv % 10;
}

int main() {
    FAST_IO
    cin >> n >> m;
    init_vis();
    FOR(y, 1, n+1) {
        FOR(x, 1, m+1) {
            cin >> vis[y][x];
            vis[y][x] -= '0';
        }
    }
    FOR(y, 1, n+1) {
        FOR(x, 1, m+1) {
            if(same_space[y][x] || vis[y][x]) continue;
            bfs(y, x);
        }
    }
    int py, px;
    char tmp[4], sum;
    FOR(y, 1, n+1) {
        FOR(x, 1, m+1) {
            if(same_space[y][x]) {cout << 0;continue;}
            sum = 1;
            FOR(i, 0, 4) {
                py = y+dy[i], px = x+dx[i];
                if(same_space[py][px] == 0) {tmp[i] = 0; continue;}
                tmp[i] = *same_space[py][px];
                sum += tmp[i];
                *same_space[py][px] = 0;
            }
            cout << sum % 10;
            FOR(i, 0, 4) {
                if(tmp[i] == 0) continue;
                *same_space[y+dy[i]][x+dx[i]] = tmp[i];
            }
        }
        cout << '\n';
    }
    return 0;
}