#include <cstdio>

char output[9*18+1] = "0 0 0 0 0 0 0 0 0\n0 0 0 0 9 0 0 0 0\n9 0 0 0 0 0 0 0 0\n1 0 0 0 0 0 0 0 0\n5 4 7 1 8 9 2 3 6\n0 0 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 0 0\n3 9 8 5 2 4 7 6 1\n7 6 4 9 1 8 3 5 2\n";
int main() {
    fwrite(output, sizeof(char), sizeof(output), stdout);
    return 0;
}

/*
랜덤한 값으로 스도쿠를 만들어서 cnt 100000을 넘길때까지의 경우를 몇가지 찾은다음
이게 스도쿠가 풀리는 값인지(유효한 스도쿠인지) 확인한 뒤 전처리 & 제출
*/