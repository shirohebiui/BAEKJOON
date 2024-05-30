#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int n; std::cin >> n;
	if(n < 100) {
		std::cout << n << "\n";
	} else {
		int t1 = n/100;
		int t2 = (n%100)/10;
		int t3 = n%10;
		int res = (t1-1) * 5 + 99 ;
		for(int i=1; i<=4; i++) {
			if(t1 - i >= 0 && t1 - i < t2 && t1 - i*2 >= 0) res++;
			else if(t1 - i >= 0 && t1 - i == t2 && t1 - i*2 >= 0 && t1 - i*2 <= t3) res++;

			if(t1 + i < t2 && t1 + i*2 <= 9) res++;
			else if(t1 + i == t2 && t1 + i*2 <= t3) res++;
		}
		if(t1 < t2) res++;
		else if(t1 == t2 && t1 <= t3) res++;
		std::cout << res << "\n";
	}
	return 0;
}