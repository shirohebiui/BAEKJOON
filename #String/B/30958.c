#include <stdio.h>

char song[100001];
int alpha[26];
int main() {
    int len; scanf(" %d", &len);
    scanf(" %[^\n]s", song);
    for(int i=0; song[i] != '\0'; i++) {
        if(song[i] <= 'z' && song[i] >='a')
            alpha[song[i] - 'a']++;
    }
    int max = 0;
    for(int i=0; i<26; i++) {
        max = max > alpha[i] ? max : alpha[i];
    }
    printf("%d\n", max);
    return 0;
}