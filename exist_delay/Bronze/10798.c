#include <stdio.h>
#include <string.h>
/*
i<count[j]인데 j<count[i]로 적어놓고 왜 안되지 했다.
조건을 잘 적도록하자...
*/
int main()
{
    char str[5][15]={0};
    int count[5];
    for(int i=0;i<5;i++)
    {
        scanf("%s", str[i]);
        count[i] = strlen(str[i]);
        //printf("%d\n", count[i]);
    }
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<5;j++)
            if(i<count[j])
            {
                //printf("%d %d: %c\n", j, i, str[j][i]);
                printf("%c", str[j][i]);
            }
    }
    printf("\n");
    return 0;
}