#include <stdio.h>
#include <string.h>
#include <stdbool.h>
/*
8 x 8 크기의 체스판
1,1~8,8까지의 크기
킹의 좌표 주어짐
돌의 좌표 주어짐
움직이는 횟수 N주어짐

돌이나 킹이 주어진 8x8을 벗어나는 입력이 주어질경우 처리하지않음

결과
킹의 위치, 돌의 위치 출력

해결과정
알파뱃배열을 불러오고 A~H까지 대응하여 숫자로 치환한뒤 각오브젝트의 좌표에 대입시킨다.
R : 한 칸 오른쪽으로
L : 한 칸 왼쪽으로
B : 한 칸 아래로
T : 한 칸 위로
RT : 오른쪽 위 대각선으로
LT : 왼쪽 위 대각선으로
RB : 오른쪽 아래 대각선으로
LB : 왼쪽 아래 대각선으로
각기 대응하는 처리를 해준다.
*/

int KY, SY;
char KX, SX;

//A 65 H 72 (x축)

int is_valid(int X, int Y) {
    if(X > 72 || X <65 || Y > 8 || Y < 1)
        return false;
    return true;
}

int move(int x, int y) {
    //King의 위치에서 다음공간이 있는지 검사
    int Next_KX = KX + x;
    int Next_KY = KY + y;
    if(!is_valid(Next_KX, Next_KY)) //위치가 유효하지 않음 -> stop
        return false;

    //King의 다음 위치에 돌이 위치하는지 검사
    
    if(Next_KX == SX && Next_KY == SY) {
        //king과 stone의 위치가 겹칠 경우
        int Next_SX = SX + x;
        int Next_SY = SY + y;
        //Stone의 다음 위치 탐색
        if(!is_valid(Next_SX, Next_SY)) //위치가 유효하지 않음 -> stop
            return false;
        
        //king과 stone을 이동
        KX = Next_KX; KY = Next_KY;
        SX = Next_SX; SY = Next_SY;
    } else {
        //king과 stone의 위치가 겹치지 않은 경우
        //king 이동
        KX = Next_KX; KY = Next_KY;
    }
}

void handleDirection(const char* direction) {
    if (strcmp(direction, "R") == 0) {
        move(1,0);
    } else if (strcmp(direction, "L") == 0) {
        move(-1,0);
    } else if (strcmp(direction, "B") == 0) {
        move(0,-1);
    } else if (strcmp(direction, "T") == 0) {
        move(0,1);
    } else if (strcmp(direction, "RT") == 0) {
        move(1,1);
    } else if (strcmp(direction, "LT") == 0) {
        move(-1,1);
    } else if (strcmp(direction, "RB") == 0) {
        move(1,-1);
    } else if (strcmp(direction, "LB") == 0) {
        move(-1,-1);
    } else {
        printf("Invalid direction: %s\n", direction);
    }
}

int main()
{
    int N;
    scanf("%c%d %c%d %d", &KX, &KY, &SX, &SY, &N);
    /* printf("%c%d\n", KX, KY);
    printf("%c%d\n", SX, SY);
    printf("%d\n", N); */
    char mv[3];
    while(N--) {
        scanf("%2s", mv);
        handleDirection(mv);
    }
    printf("%c%d\n", KX, KY);
    printf("%c%d\n", SX, SY);
    return 0;
}