#include <iostream>
using namespace std;

#include <cstring>
char dice[4][3], tmp[4][3];

#define bottom dice[3][1]
#define top dice[1][1]
char board[20][20]; int n, m, x, y, cc;
void test();
void excute() {
    if(board[y][x] == '0') board[y][x] = bottom;
    else {bottom = board[y][x]; board[y][x] = '0';}
    // cout << x << "," << y << "\n";
    // test();
    cout << top << "\n";
}
void East() {
    tmp[1][0] = dice[3][1];
    tmp[1][1] = dice[1][0];
    tmp[1][2] = dice[1][1];
    tmp[3][1] = dice[1][2];

    dice[1][0] = tmp[1][0];
    dice[1][1] = tmp[1][1];
    dice[1][2] = tmp[1][2];
    dice[3][1] = tmp[3][1];
}
void West() {
    tmp[1][0] = dice[1][1];
    tmp[1][1] = dice[1][2];
    tmp[1][2] = dice[3][1];
    tmp[3][1] = dice[1][0];

    dice[1][0] = tmp[1][0];
    dice[1][1] = tmp[1][1];
    dice[1][2] = tmp[1][2];
    dice[3][1] = tmp[3][1];
}
void South() {
    tmp[3][1] = dice[3][1];

    dice[3][1] = dice[2][1];
    dice[2][1] = dice[1][1];
    dice[1][1] = dice[0][1];
    dice[0][1] = tmp[3][1];
}
void North() {
    tmp[0][1] = dice[0][1];

    dice[0][1] = dice[1][1];
    dice[1][1] = dice[2][1];
    dice[2][1] = dice[3][1];
    dice[3][1] = tmp[0][1];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //input
    cin >> n >> m >> y >> x >> cc;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
        }
    }

    //init
    memset(dice, '0', sizeof(dice));

    //func
    #define isSafe(y,x) (y>=0 && y<n && x>=0 && x<m)
    while(cc--) {
        int cmd; cin >> cmd;
        switch (cmd)
        {
        case 1: //East
            if(!isSafe(y, x+1)) break;
            ++x;
            East();
            excute();
            break;
        case 2: //West
            if(!isSafe(y, x-1)) break;
            --x;
            West();
            excute();
            break;
        case 3: //North
            if(!isSafe(y-1, x)) break;
            --y;
            North();
            excute();
            break;
        case 4: //South
            if(!isSafe(y+1, x)) break;
            ++y;
            South();
            excute();
            break;
        
        default:
            cout << "error\n";
            break;
        }
    }

    return 0;
}

void test() {
    for(int i=0; i<4; i++) {
        for(int j=0; j<3; j++) {
            cout << dice[i][j] << " ";
        }
        cout << "\n";
    }
}