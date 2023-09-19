#include <stdio.h>

int _pow(int k) {
	return k*k;
}

int IsValidTri(int a, int b, int c) {
	if(_pow(a) == _pow(b) + _pow(c))
		return 1;
	if(_pow(b) == _pow(a) + _pow(c))
		return 1;
	if(_pow(c) == _pow(a) + _pow(b))
		return 1;
	return 0;
}

int main() {
	int a, b, c;
	while(1) {
		scanf("%d %d %d", &a, &b, &c);
		if(a && b && c) {
			if(IsValidTri(a,b,c)) {
				printf("right\n");
			} else {
				printf("wrong\n");
			}
		} else {
			return 0;
		}
	}
	return 0;
}