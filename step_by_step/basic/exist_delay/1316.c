#include <stdio.h>
#include <string.h>
/*
문자열을 N개 입력 받고 그룹 단어의 개수를 출력한다.
문자열의 최대길이는 100이다. 따라서 문자열이 입력될 버퍼(배열)의 크기는 100이다.

문자열당 아래 과정을 한다.
#1 : 알파뱃 배열 26공간을 만들어 0으로 초기화한다.
#2 : scanf로 문자열으 입력받고 문자열의 시작을 ptr포인터로 받고 해당 포인터의 문자를 위의 알파뱃배열에 대조해 대응하는 위치로간다.
#3 : 0이면 +1을하고 문자의 반복이 끝날때까지 ptr+1과 strchr을 통해 이동한다.
#3 수정 : strchr은 필요없다 *ptr, *(ptr+1)의 문자가 같은지 검사하면된다.
-> aaabbb가 문자열이라면 ptr은 a시작점에서 b로 이동하게될것이다.
#4 : 그후 달라진 문자가 등장시 대해 위의 #2부터 다시 실행한다.
#5 : 알패뱃배열중 1이 저장된 부분만 해당 알패뱃 그룹 문자열이 될것이다. if문을 통해 1끼리만 더한다. -> 한번만 연속해서 나온것만 그룹문자!
#5 수정 : 그룹문자란 연속된 문자끼리 이뤄진 문자다 즉 new라는 단어도 그룹문자다.
    group_word_count라는 문자열하나의 그룹문자여부를 판단할 변수를 만들고 이를 1로 초기화후 문자의 비연속성을 검사해 (alpha_count > 1 경우) 참이면 0으로 초기화한다.
    추후 이 group_word_count를 시그마(합연산)하면 될것이다.'

    성공!
*/
int main()
{
    char str[100];
    int N;
    int sum=0;
    int group_word_count[10000] ={0};
    char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
                'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        // #1
        int alpha_count[26] = {0};

        // #2
        scanf("%s", str);
        char *ptr = str;
        
        char tmp = *ptr; //문자의 시작
        while(*ptr != NULL)
        {
            // #3
            for(int j=0;j<26;j++)
                if(alpha[j] == tmp)
                {
                    alpha_count[j]++;
                    
                    //문자의 연속이 끝날때까지 loop
                    while(tmp == *ptr)
                        ptr++;
                    tmp = *ptr; //다음 문자를 tmp에 저장
                    j=0;
                }
        }
        // #5
        group_word_count[i]=1;
        for(int j=0;j<26;j++)
        {
            if(alpha_count[j]>1)
            {
                group_word_count[i]=0;
            }
        }
        sum+=group_word_count[i];
    }
    printf("%d\n", sum);

    return 0;
}