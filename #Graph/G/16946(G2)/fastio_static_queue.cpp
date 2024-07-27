#include <cstdio>
#define FOR(val, start, end) for(int val=(start); val<(end); val++)

#define MAX_SIZE 1002
int n, m;
char vis[MAX_SIZE][MAX_SIZE], *same_space[MAX_SIZE][MAX_SIZE];
void init_vis() {
    char *p = &vis[0][0];
    while(p != &vis[MAX_SIZE-1][MAX_SIZE-1]) *p++ -= '0';
    int mm = m+1, nn = n+1;
    vis[0][mm] = vis[nn][mm] = vis[nn][0] = vis[0][0] = 1;
    for(int i=1; i<nn; ++i) vis[i][0] = vis[i][mm] = 1;
    for(int i=1; i<mm; ++i) vis[0][i] = vis[nn][i] = 1;
}
char dy[4] = {-1, 0, 1, 0};
char dx[4] = {0, 1, 0, -1};

//setting : cnt of same space
void bfs(int y, int x) {
    short pos[1000*1000][2], py, px;
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
            pos[rear][0] = py, pos[rear][1] = px, rear++, mv++;
        }
        front++;
    }
    vis[y][x] = mv % 10;
}

#include <cstring>
char input[1000][1001], *rb = &input[0][0];
char output[1000][1001], *wb = &output[0][0];
int main() {
    //input & init
    scanf("%d %d ", &n, &m);
    fread(input, sizeof(char), n*(m+1), stdin);
    FOR(y, 1, n+1) {
        memmove(&vis[y][1], rb, m); rb+=m+1;
    }
    init_vis();

    //func
    //chk cnt of same space
    FOR(y, 1, n+1) {
        FOR(x, 1, m+1) {
            if(same_space[y][x] || vis[y][x]) continue;
            bfs(y, x);
        }
    }

    //write sum of adj cnt of space
    int py, px;
    char tmp[4], sum;
    FOR(y, 1, n+1) {
        FOR(x, 1, m+1) {
            if(same_space[y][x]) {*wb++ = '0';continue;}
            sum = 1;
            FOR(i, 0, 4) {
                py = y+dy[i], px = x+dx[i];
                if(same_space[py][px] == 0) {tmp[i] = 0; continue;}
                tmp[i] = *same_space[py][px];
                sum += tmp[i];
                *same_space[py][px] = 0;
            }
            *wb++ = sum%10 + '0';
            FOR(i, 0, 4) {
                if(tmp[i] == 0) continue;
                *same_space[y+dy[i]][x+dx[i]] = tmp[i];
            }
        }
        *wb++ = '\n';
    }

    //answer
    fwrite(output, sizeof(char), n*(m+1), stdout);
    return 0;
}