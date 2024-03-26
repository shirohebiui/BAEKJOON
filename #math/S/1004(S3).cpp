#include <iostream>
#define isInside(rx, ry, r, x, y) (r*r < ((rx-x)*(rx-x) + (ry-y)*(ry-y)))
int main() {
    std::ios_base::sync_with_stdio(false);
    int tc; std::cin >> tc;
    while(tc--) {
        int sy, sx, dy, dx, n;
        std::cin >> sx >> sy >> dx >> dy >> n;
        int cnt = 0;
        while(n--) {
            int ry, rx , r;
            std::cin >> rx >> ry >> r;
            if(isInside(rx, ry, r, sx, sy) != isInside(rx, ry, r, dx, dy)) cnt++;
        }
        std::cout << cnt << "\n";
    }
    return 0;
}