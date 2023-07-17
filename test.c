#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _double_node
{
	char *data;
	struct _double_node *prev;
	struct _double_node *next;
} double_node;

double_node *head, *tail;

void init_dlist(void)
{
	head = (double_node*)malloc(sizeof(double_node));
	tail = (double_node*)malloc(sizeof(double_node));
	head->next = tail;
	head->prev = head;
	tail->next = tail;
	tail->prev = head;
}
int sort_dic(char *a, char *b)
{
    char *ptr_A = a;
    char *ptr_B = b;
    while(*ptr_A == *ptr_B)
    {
        ptr_A++;
        ptr_B++;
        if(*ptr_A == '\0') //문자열 끝에 도달시 종료
            return 2;
    }
    //  A가 사전순으로 후순위인가?
    //  참->1return , 거짓->0return
    if(*ptr_A < *ptr_B)
        return 1;
    else
        return 0;
}
double_node *Insert_sort(char *str)
{
	double_node *s;
	double_node *i;
	s = (double_node*)malloc(sizeof(double_node));
	i = (double_node*)malloc(sizeof(double_node));
	if(head->next == tail)
	{
		i->data = str;
		i->prev = head->prev;
		i->next = tail->next;
		head->next = i;
		tail->prev = i;
	}
	else
	{
		s = head->next;
		while(1)
		{
			if(strlen(s->data) > strlen(str))
            //문자열의 길이 비교
				break;
            else
            if(strlen(s->data) == strlen(str))
            //문자열의 길이가 같을경우 사전순 비교
            {
                int info = sort_dic(str, s->data);
                // 2는 동일(함수탈출 삽입하지않음), 1은 앞에 삽입 0은 다음검색
                if(info == 2)
                    return 0;
                if(info == 1)
                    break;
            }
			s = s->next;
			if(s==tail)
				break;
		}
		i->data = str;
		i->prev = s->prev;
		i->next = s;
		s->prev->next = i;
		s->prev = i;
	}
	return i;
}

void print_all(double_node *p)
{
	while(p != tail)
	{
		printf("%s\n", p->data);
		p=p->next;
	}
}

void main(void)
{
	init_dlist();
    char arr[20000][50];
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++)
    {
        scanf("%s", arr[i]);
        Insert_sort(arr[i]);
    }
    print_all(head->next);
}
