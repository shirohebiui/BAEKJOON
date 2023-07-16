#include <stdio.h>

int map(int k)
{
    if(k==8)
        return 10;
    else if(k==5)
        return 9;
    else if(k==4)
        return 8;
    else if(k==9)
        return 7;
    else if(k==1)
        return 6;
    else if(k==7)
        return 5;
    else if(k==6)
        return 4;
    else if(k==3)
        return 3;
    else if(k==2)
        return 2;
    else if(k==0)
        return 1;
    else
    {
        printf("error");
        return 0;
    }
}
void weight(int k, int *arr)
{
    //한자릿수 1~9까지에 가중치
    if(k<10)
        *arr=map(k)*100+99;
    //10~100까지의 가중치
    else if(k<100)
    {
        *arr=map(k/10)*100;
        *arr+=map(k%10);
    }
}
void swap(int *a, int *b)
{
    int tmp= *a;
    *a = *b;
    *b = tmp;
}
int main()
{
    int m,n;
    scanf("%d %d", &m, &n);
    int arr[101][2]={0};

    //배열에 숫자 차례로 기입 후 가중치로 변환
    //ex 32-> arr[32]=32
    for(int i=m;i<n+1;i++)
    {
        arr[i][0]=i; //차례로 적힌 숫자
        weight(i,&arr[i][1]);
    }

    for(int i=n;i>m-1;i--)
    {
        for(int j=m;j<i;j++)
        {
            //arr[j]는 현재값, arr[j+1]은 다음값
            //arr[j]의 가중치는 w_arr[arr[j]]이다.
            //가중치를 비교후 스왑
            if(arr[j][1]<arr[j+1][1])
            {
                swap(&arr[j][0], &arr[j+1][0]);
                swap(&arr[j][1], &arr[j+1][1]);
            }
        }
    }

    //최종 출력
    int count=0;
    for(int i=m;i<n+1;i++)
    {
        printf("%d ", arr[i][0]);
        //한줄에 10개 출력후 줄바꿈
        if(count++==9)
        {
            printf("\n");
            count=0;
        }
    }
    printf("\n");
    return 0;
}