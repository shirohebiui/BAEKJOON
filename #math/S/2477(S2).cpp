#include <iostream>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define right 1
#define left 2
#define down 3
#define up 4

typedef struct vertex{
    int arrow, y, x;
}vertex;
vertex v[6];

int main() {
    int i;
    std::ios_base::sync_with_stdio(false);

    //input
    int getamount; std::cin >> getamount;
    int uy, dy, rx, lx, dist, arrow;
    uy = dy = rx = lx = 0;
    for(i=0; i<6; i++) {
        std::cin >> arrow >> dist;
        v[i].arrow = arrow;
        switch (arrow)
        {
        case right:
            v[i].y = v[i-1].y;
            v[i].x = v[i-1].x + dist;
            rx = max(rx, v[i].x);
            break;
        case left:
            v[i].y = v[i-1].y;
            v[i].x = v[i-1].x - dist;
            lx = min(lx, v[i].x);
            break;
        case up:
            v[i].x = v[i-1].x;
            v[i].y = v[i-1].y + dist;
            uy = max(uy, v[i].y);
            break;
        case down:
            v[i].x = v[i-1].x;
            v[i].y = v[i-1].y - dist;
            dy = min(dy, v[i].y);
            break;
        }
    }

    #define prev v[i].arrow
    #define next v[(i+1)%6].arrow
    #define x v[i].x
    #define y v[i].y
    for(i=0; i<6; i++) {
        if(x != rx && x != lx && y != uy && y != dy) break;
    }
    
    int csize;
    if(prev == up && next == right) {
        csize = abs(x-rx) * abs(y-dy);
    } else if(prev == right && next == down) {
        csize = abs(x-lx) * abs(y-dy);
    } else if(prev == down && next == left) {
        csize = abs(x-lx) * abs(y-uy);
    } else if(prev == left && next == up) {
        csize = abs(x-rx) * abs(y-uy);
    }

    std::cout << getamount*(abs(rx-lx) * abs(uy-dy) - csize) << "\n";
    return 0;
}