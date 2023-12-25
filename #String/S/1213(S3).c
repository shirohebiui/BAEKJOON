#include <stdio.h>
#include <string.h>

char text[51];
char alpha[26];
char answer[51];

int main() {
    //input
    scanf("%s", text);

    //alpha cnt
    int len = strlen(text);
    for(int i=0; i<len; i++) {
        alpha[text[i]-'A']++;
    }

    //check odd
    int odd = 0, center;
    for(int i=0; i<26; i++) {
        if(alpha[i]%2 != 0) {
            odd++;
            center = i;
            alpha[i]--;
        }
    }
    //IsValid?
    if(odd > 1) {
        printf("I'm Sorry Hansoo\n");
        return 0;
    }

    //gen palindrome
    int front = 0, back = len-1;
    for(int x=0; x<26; x++) {
        // printf("%d ", alpha[x]);
        while(alpha[x] > 0) {
            answer[front++] = x+'A';
            answer[back--] = x+'A';
            alpha[x]-=2;
        }
    }
    if(odd) answer[front] = center+'A';

    //answer
    printf("%s\n", answer);
    return 0;
}