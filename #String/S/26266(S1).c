#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 200001

char text[MAX_LEN], cipher[MAX_LEN];
char key[MAX_LEN];

int isloop(int loop, int length) {
    for(int i=0; i<length; i++) {
        if(cipher[i] != (key[i%loop] + text[i])%26) return 0;
    }
    return 1;
}

int main() {
    //input
    scanf(" %s %s", text, cipher);
    int length = strlen(text);

    //gen key
    for(int i=0; i<length; i++) {
        text[i] -= 'A';
        cipher[i] -= 'A';
        if(text[i] >= cipher[i])
            key[i] = (26 - text[i] + cipher[i] );
        else
            key[i] = cipher[i] - text[i];
    }
    //find min loop key
    //평문길이 1
    if(length == 1) {
        printf("%c\n", key[0]+ '@');
        return 0;
    }
    //평문길이 1이상
    for(int i=1; i<length; i++) {
        if(length%i == 0)
        if(isloop(i, length)) {
            for(int j=0; j<i; j++) {
                printf("%c", key[j]+'@');
            }
            printf("\n");
            return 0;
        }
    }
    //반복이 없는경우
    for(int i=0; i<length; i++) {
        printf("%c", key[i]+'@');
    }
    printf("\n");
    return 0;
}