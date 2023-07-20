#include <stdio.h>

int main()
{
    int prev, now, flag;
    scanf(" %d", &now);
    prev = now;
    for(int i=0; i<7; i++) {
        scanf(" %d", &now);
        flag = now - prev;
        prev = now;
        if(flag == 1 || flag == -1) {continue;}
        else {break;}
    }
    switch (flag)
    {
    case 1:
        printf("ascending\n");
        break;
    case -1:
        printf("descending\n");
        break;
    default:
        printf("mixed\n");
    }
    return 0;
}