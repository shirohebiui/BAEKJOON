#include <stdio.h>
#include <string.h>
#define SIZE 100

int main() {
    char cmd[SIZE+1]; cmd[SIZE] = '\0';
    memset(cmd, '2', SIZE); // 222222~
    int win = 0; scanf(" %d", &win);

    //승률 100%를 만들어가는 과정
    for(int i=0; i<SIZE; i++) {
        if(win == SIZE) break;
        cmd[i] = '5';
        fprintf(stdout, "? %s\n", cmd);
        fflush(stdout);
    
        int tmp; scanf(" %d", &tmp);
        if( tmp < win ) {
            cmd[i] = '2'; //가위로 복구
        } else if( tmp == win ) {
            cmd[i] = '0'; //가위,보 둘다아님 -> 주먹
            win++;
        } else {
          //cmd[i] = '5'; //보가 맞음
            win++;
        }
    }

    //승률 100%짜리 답지를 통해 문제 역으로 도출
    // 2->5, 5->0, 0->2
    for(int i=0; i<SIZE; i++) {
        if(cmd[i] == '2') {
            cmd[i] = '5';
        } else if(cmd[i] == '5') {
            cmd[i] = '0';
        } else {
            cmd[i] = '2';
        }
    }

    fprintf(stdout, "! %s\n", cmd);
    fflush(stdout);
    return 0;
}