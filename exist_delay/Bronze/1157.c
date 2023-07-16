#include <stdio.h>
#include <unistd.h>
#include <string.h>
/*
문자열이 입력된다.
문자열에서 가장 많이 사용된 알파뱃을 대문자로 출력하는 문제이다.

알파뱃은 28개이다.
따라서 int 형 28크기의 배열을 만들어 각 알파뱃마다 count를 매겨주면 좋겠다.

*/
int main()
{
    char arr[1000000];
    scanf("%s", arr);
    int count[28] = {0}; //0으로 초기화
    int max=strlen(arr);
    //printf("%s\n", arr);
    char *ptr=arr;
    //문자열의 시작부분을 포인터로잡고 +1씩 해나가 NULL를 만나면 문자열의 끝이다.
    while(*ptr!=NULL)
    {
        if(*ptr == 'a' || *ptr == 'A')
            count[0]++;
        else if(*ptr == 'b' || *ptr == 'B')
            count[1]++;
        else if(*ptr == 'c' || *ptr == 'C')
            count[2]++;
        else if(*ptr == 'd' || *ptr == 'D')
            count[3]++;
        else if(*ptr == 'e' || *ptr == 'E')
            count[4]++;
        else if(*ptr == 'f' || *ptr == 'F')
            count[5]++;
        else if(*ptr == 'g' || *ptr == 'G')
            count[6]++;
        else if(*ptr == 'h' || *ptr == 'H')
            count[7]++;
        else if(*ptr == 'i' || *ptr == 'I')
            count[8]++;
        else if(*ptr == 'j' || *ptr == 'J')
            count[9]++;
        else if(*ptr == 'k' || *ptr == 'K')
            count[10]++;
        else if(*ptr == 'l' || *ptr == 'L')
            count[11]++;
        else if(*ptr == 'm' || *ptr == 'M')
            count[12]++;
        else if(*ptr == 'n' || *ptr == 'N')
            count[13]++;
        else if(*ptr == 'o' || *ptr == 'O')
            count[14]++;
        else if(*ptr == 'p' || *ptr == 'P')
            count[15]++;
        else if(*ptr == 'q' || *ptr == 'Q')
            count[16]++;
        else if(*ptr == 'r' || *ptr == 'R')
            count[17]++;
        else if(*ptr == 's' || *ptr == 'S')
            count[18]++;
        else if(*ptr == 't' || *ptr == 'T')
            count[19]++;
        else if(*ptr == 'u' || *ptr == 'U')
            count[20]++;
        else if(*ptr == 'v' || *ptr == 'V')
            count[21]++;
        else if(*ptr == 'w' || *ptr == 'W')
            count[22]++;
        else if(*ptr == 'x' || *ptr == 'X')
            count[23]++;
        else if(*ptr == 'y' || *ptr == 'Y')
            count[24]++;
        else if(*ptr == 'z' || *ptr == 'Z')
            count[25]++;
        
        ptr++;
    }
    char alpha[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
                'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int max_count=0;
    int question; //최대count가 같은 문자가 있는지 중복여부검사
    int result;
    for(int i=0;i<26;i++)
    {
        if(max_count < count[i])
        {
            question=0; //중복해제
            max_count = count[i];
            result = i;
        }
        else if(max_count == count[i])
            question=1; //중복체크
    }
    if(question == 0)
        printf("%c\n", alpha[result]);
    else if(question == 1)
        printf("?\n");
    return 0;
}