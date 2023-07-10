#include <stdio.h>
#include <string.h>
/*
대학생이면서 학점에 관심이없어 학점계산을 해본적이없어서 학점계산이 생소했다.
글을 잘못읽어 학점의 총합으로 나누는것을 과목평점총합의 평점으로 나누는것으로 봐 이 착오로 풀이에 시간이 지연됐다.
글을 잘읽어 조건을 잘 정리하자.
*/
float cal(float k, char *s)
{
    if (!strcmp(s, "A+"))
        return k * 4.5;
    else if (!strcmp(s, "A0"))
        return k * 4.0;
    else if (!strcmp(s, "B+"))
        return k * 3.5;
    else if (!strcmp(s, "B0"))
        return k * 3.0;
    else if (!strcmp(s, "C+"))
        return k * 2.5;
    else if (!strcmp(s, "C0"))
        return k * 2.0;
    else if (!strcmp(s, "D+"))
        return k * 1.5;
    else if (!strcmp(s, "D0"))
        return k * 1.0;
    else if (!strcmp(s, "F"))
        return 0;
}
int main()
{
    //20줄에 걸쳐 입력된다.
    float score = 0; //과목 점수 (3.0 4.0등의 형식으로 입력받아야함)

    char grade[5]; //과목 학점
    char tmp[50]; //과목명(임시)
    

    float sum=0; //내 학점
    int all_grade=0; //총 학점(?)
    for(int i=0;i<20;i++)
    {
        scanf("%s %f %s", tmp, &score, grade);
        if(strcmp(grade, "P"))
        {
            sum+=cal(score, grade);
            all_grade+=score;
        }
    }
    if(all_grade==0)
        printf("0\n");
    else
        printf("%f\n", sum/all_grade);
    return 0;
}