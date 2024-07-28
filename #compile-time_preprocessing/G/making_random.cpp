#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)
int a[10][10];
bool c[10][10];
bool c2[10][10];
bool c3[10][10];
int n=9;
int cnt=0;
inline int square(int x, int y) {
    return (x/3)*3+(y/3);
}
bool go(int z) {
    cnt++;
    if (cnt >= 10000000) {
        return true;
    }
    if (z == 81) {
        return true;
    }
    int x = z/n;
    int y = z%n;
    if (a[x][y] != 0) {
        return go(z+1);
    } else {
        for (int i=1; i<=9; i++) {
            if (c[x][i] == 0 && c2[y][i] == 0 && c3[square(x,y)][i]==0) {
                c[x][i] = c2[y][i] = c3[square(x,y)][i] = true;
                a[x][y] = i;
                if (go(z+1)) {
                    return true;
                }
                a[x][y] = 0;
                c[x][i] = c2[y][i] = c3[square(x,y)][i] = false;
            }
        }
    }
    return false;
}

int best = 0;
constexpr int vissize = 10*10;
constexpr int outsize = 10*10*4;
int make[10][10];
void test() {
    FOR(i, 0, 9) {
        FOR(j, 0, 9) {
            cout << make[i][j] << ' ';
        }
        cout << '\n';
    }
}
char col[10][10], row[10][10], sq[3][3][10];
void pray() {
    while(best < 100000) {
        FOR(y, 0, 6) {
            int i = rand()%10;
            while(1) {
                int x = time(NULL)%10, v = rand()%10;
                if(col[i][v] == 0 && row[x][v] == 0 && sq[i/3][x/3][v] == 0) {
                    col[i][v] = row[x][v] = sq[i/3][x/3][v] = 1;
                    make[i][x] = v;
                    break;
                }
            }
        }
        cnt = 0;
        go(0);
        if(cnt > best) {
            best = cnt;
            cout << "best : " << best << '\n';
            test();
        }
        memmove(a, make, outsize);
        memset(c, 0x00, vissize);
        memset(c2, 0x00, vissize);
        memset(c3, 0x00, vissize);
        memset(col, 0x00, vissize);
        memset(row, 0x00, vissize);
        memset(sq, 0x00, sizeof(sq));
    }
}

int main() {
    pray();
    return 0;
}