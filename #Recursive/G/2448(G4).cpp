#include <iostream>
#include <string.h>
char star[3073][6144]; int n;

void init_star() {
    memset(star,' ', sizeof(star));
    memmove(&star[0][0], "***** ", 6);
    memmove(&star[1][0], " * *  ", 6);
    memmove(&star[2][0], "  *   ", 6);
}

int ysize, xsize;
void paint() {
    xsize = ysize << 1;
    int ux = xsize/2;
    for(int i=0; i<ysize; i++) {
        memmove(&star[i][xsize], &star[i][0], xsize);
        memmove(&star[i+ysize][ux], &star[i][0], xsize);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

    std::cin >> n;
    init_star();
    
    for(ysize=3; ysize<n; ysize <<= 1) {
        paint();
    }
    xsize = n << 1;
    for(int i=n-1; i>=0; i--) {
        for(int j=0; j<xsize; j++) {
            std::cout << star[i][j];
        }
        std::cout << "\n";
    }
    return 0;
}