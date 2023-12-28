#include <stdio.h>
#include <string.h>

int main()
{
    int TestCase; scanf("%d", &TestCase);
    while(TestCase--) {
        int Y= 0, K = 0;
        for(int i=0; i<9; i++) {
            int score; 
            scanf(" %d", &score); Y += score;
            scanf(" %d", &score); K += score;
        }
        if(Y == K)     printf("Draw\n");
        else if(Y > K) printf("Yonsei\n");
        else           printf("Korea\n");
    }
    return 0;
}