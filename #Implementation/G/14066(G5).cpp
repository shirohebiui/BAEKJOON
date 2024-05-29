#include <iostream>
#include <cstring>
using namespace std;

char out[1001][1001];
char prio[1001][1001];
int h = 1000, w;
char square[6][8] = {
    "..+---+",
    "./   /|",
    "+---+ |",
    "|   | +",
    "|   |/.",
    "+---+..",
};

void paint(int y, int x, int layer) {
    int py, px;
    for(int i=1; i<=6; i++) {
        for(int j=0; j<7; j++) {
            py = y-i; px = x+j;
            h = min(h, py);
            if(prio[py][px] <= layer && square[6-i][j] != '.') {
                out[py][px] = square[6-i][j];
                prio[py][px] = layer;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    memset(out, '.', sizeof(out));

    int n, m; cin >> n >> m;
    int cnt[51][51];
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> cnt[i][j];
        }
    }
    int y = 1000, x = 0;
    for(int i=n; i>0; i--) {
        for(int j=1; j<=m; j++) {
            for(int k=0; k<cnt[i][j]; k++) {
                h = min(h, y-(n-i)*2-k*3);
                w = max(w, x+(n-i)*2+(j-1)*4+7);
                paint(y-(n-i)*2-k*3, x+(n-i)*2+(j-1)*4, i);
            }
        }
    }
    for(int i=h; i<1000; i++) {
        for(int j=0; j<w; j++) {
            cout << out[i][j];
        }
        cout << "\n";
    }
    for(int i=0; i<6; i++) {
        for(int j=0; j<7; j++) {

        }
    }
    return 0;
}