#include <stdio.h>

int main(){
    int len[3];
    while(1) {
        scanf(" %d %d %d", &len[0], &len[1], &len[2]);
        if(len[0] + len[1] + len[2] == 0) break;

        if(len[0] + len[1] <= len[2] ) printf("Invalid\n");
        else if(len[1] + len[2] <= len[0]) printf("Invalid\n");
        else if(len[2] + len[0] <= len[1]) printf("Invalid\n");

        else if(len[0] == len[1] && len[1] == len[2]) printf("Equilateral\n");

        else if(len[0] == len[1] && len[1] != len[2]) printf("Isosceles\n");
        else if(len[0] == len[2] && len[1] != len[2]) printf("Isosceles\n");
        else if(len[1] == len[2] && len[0] != len[1]) printf("Isosceles\n");

        else printf("Scalene\n");
    }
}