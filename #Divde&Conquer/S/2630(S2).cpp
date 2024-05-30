#include <iostream>
#define SIZE 128
char board[SIZE][SIZE]; int n; 
int blue, white;

int cq(char y, char x, short size) {
    if(size == 1) return board[y][x];
    char a = (char)cq(y+size/2, x+size/2, size/2);
    char b = (char)cq(y+size/2, x, size/2);
    char c = (char)cq(y, x+size/2, size/2);
    char d = (char)cq(y, x, size/2);
    if(a==b && b==c && c==d) {
        if(a == -1) return -1;
        if(size == n) {
            blue += board[y][x];
            white += (board[y][x] == 0);
        }
        return board[y][x];
    } else {
        // std::cout << "counting[pos] = " << y << "," << x << "," << size <<" ... ";
        blue  += (a==1) + (b==1) + (c==1) + (d==1);
        white += (a==0) + (b==0) + (c==0) + (d==0);
        // std::cout << "blue " << (a==1) + (b==1) + (c==1) + (d==1) << ", white " << (a==0) + (b==0) + (c==0) + (d==0) << "\n";
        return -1;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
    std::cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            std::cin >> board[i][j];
            board[i][j] -= '0';
        }
    }
    cq(0, 0, n);
    std::cout << white << "\n" << blue << "\n";
    return 0;
}