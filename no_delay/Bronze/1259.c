#include <stdio.h>
#include <string.h>

int main()
{
    char input[10];
    while(1) {
        scanf("%s", input);
        if(input[0] == '0')
            break;

        int max = strlen(input) - 1;
        //int half = max%2?max/2 - 1:max/2;
        int flag = 1;
        for(int i=0;i<max/2+1;i++) {
            //printf("%c %c\n", input[i], input[max - i]);
            if(input[i] != input[max - i])
                flag = 0;
        }
        if(flag)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}