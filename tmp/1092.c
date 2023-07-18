#include <stdio.h>
int N, M;
int weight[50];
long box[10000][2]= {0};
int sum=0;
//[a][0] = 무게, [a][1] = 적재여부 0미적재 1적재

void delete_box(int k)
{
    int box_weight=0;
    int location=0;
    for(int i=0;i<N) // && 나중에 합칠까?
        if(box[i][1] == 0)
        if(box[i][0] < weight[k])
        if(box_weight < box[i][0])
        {
            box_weight = box[i][0];
            location = i;
        }
    if(box_weight != 0)
    {
        box[location][1]=1;
        sum++;
    }
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        scanf("%d", wegiht[i]);
    }
    scanf("%d", M);
    for(int i=0; i<M; i++)
    {
        scanf("%ld", box[i][0]);
    }
    //여기까지 초기 입력
    int max = N*M;

    

    return 0;
}