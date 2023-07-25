#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int n) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    char S[3] = "수";
    char B[3] = "박";
    char* answer = (char*)malloc(sizeof(char) * (n * 3 + 1));
    int j=0;
    for(int i=0; i<n*3; i+=3) {
        if(i%2 == 0 ) {
            answer[j++] = S[0];
            answer[j++] = S[1];
            answer[j++] = S[2];
            
        } else {
            answer[j++] = B[0];
            answer[j++] = B[1];
            answer[j++] = B[2];
        }
    }
    answer[j] = '\0';
    return answer;
}
int main() {
    int n = 4;
    printf("%s\n" ,solution(n));
}