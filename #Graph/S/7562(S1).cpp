#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define FOR(val, s, e) for(int val=(s); val<(e); val++)

//**************************base function start**********************************
//READ
constexpr int RSZ = 1<<16;
char rbuf[RSZ], *rbp;
const char *rbp_end = rbuf + RSZ;
inline char ReadChar() {
    if(rbp == rbp_end) fread(rbp = rbuf, sizeof(char), RSZ, stdin);
    return *rbp++;
}
inline int ReadInt() {
    int ret = 0;
    for (char c = ReadChar(); c&16; ret = ret*10 + (c&15), c = ReadChar());
    return ret;
}

//WRITE
constexpr int WSZ = 1<<16;
char wbuf[WSZ]; int wbp;
const int wbp_end = WSZ - 30;

inline void wbuf_flush() {
    fwrite(wbuf, 1, wbp, stdout);
    wbp = 0;
}

inline void wbuf_write(char *p) {
    while(*p != '\0') wbuf[wbp++] = *p++;
    wbuf[wbp++] = '\n';
    if(wbp > wbp_end) wbuf_flush();
}

char output[11], output_tmp[11], *tmp;
inline char *itoa(int input) {
    if(input == 0) {*output = '0'; *(output+1) = '\0'; return output;} //0일경우 예외처리

    tmp = output_tmp+1;

    //itoa func
    while(input) {
        *tmp++ = '0' + input%10;
        input /= 10;
    } tmp--;
    char *p = output; //output pointer
    while(*tmp != '\0') *p++ = *tmp--;
    *p = '\0';
    return output;
}
//**************************base function end**********************************


struct pos {int y, x;};
int dy[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int dx[8] = {1, -1, 2, -2, 2, -2, 1, -1};

inline void func() {
    unsigned char board[300][300];
    #define INF 0xFF
    memset(board, INF, sizeof(board));
    //input
    int bsize = ReadInt();
    queue<pos> q;
    q.push({ReadInt(), ReadInt()}); 
    pos end; end.y = ReadInt(); end.x = ReadInt();

    //bfs
    #define isSafe(t) (t.y>=0 && t.y<bsize && t.x>=0 && t.x<bsize)
    #define now q.front()
    board[q.front().y][q.front().x] = 0;
    while(!q.empty()) {
        pos p;
        FOR(i, 0, 8) {
            p.y = now.y + dy[i]; p.x = now.x + dx[i];
            if(isSafe(p) && board[p.y][p.x] > board[now.y][now.x]+1) {
                board[p.y][p.x] = board[now.y][now.x]+1;
                q.push(p);
            }
        }
        if(board[end.y][end.x] < INF) break;
        q.pop();
    }

    //answer
    wbuf_write(itoa((int)board[end.y][end.x]));
}

int main() {
    fread(rbp = rbuf, sizeof(char), RSZ, stdin);
    int tc = ReadInt();
    while(tc--) {
        func();
    }
    wbuf_flush();
    return 0;
}
