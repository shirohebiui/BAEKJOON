#include <stdio.h>

int main()
{
    int X;
    scanf("%d", &X);

    int count=1;
    int i=2;
    if(X == 1)
    {
        printf("%d/%d\n", 1, 1);
    }
    else
    while(1)
    {
        if(i%2 == 0) //짝수일때
        {
            for(int j=1;j<=i;j++)
            {
                count++;
                if(count == X)
                {
                    printf("%d/%d\n",j, i+1-j);
                    break;
                }
            }
        }
        else //홀수일때
        {
            for(int j=1;j<=i;j++)
            {
                count++;
                if(count == X)
                {
                    printf("%d/%d\n", i+1-j, j);
                    break;
                }
            }
        }
        i++;
        if(count == X)
            break;
    }
    return 0;
}