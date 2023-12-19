#include <stdio.h>
#include <string.h>

int main() {
    //input
    char data[11];
    scanf("%s", data);

    //set length
    int dlen = strlen(data);

    //init arr
    for(int i=0; i<dlen; i++) {
        data[i] -= '0';
    }

    //cal
    int front, back;
    for(int i=0; i<dlen; i++) {
        //front
        for(int j=0; j<i; j++) {
            if(j==0) front = data[j];
            else     front *= data[j];
        }
        //back
        for(int k=i; k<dlen; k++) {
            if(k==i) back = data[k];
            else       back *= data[k];
        }
        //check
        if(back == front) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}