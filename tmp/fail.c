#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int N, M, V;
int base[1001][10001]= {0};
int count[1001] = {0}; //노드가 지닌 간선의갯수
int check[1001] = {0}; //stdout 출력된 노드
int visit[1001] = {0}; //방문한노드
int wait[1001] = {0}; //대기열bfs
int P=0, MAX=0; //현재 대기열 순번, 대기열 끝번호
/*
https://www.acmicpc.net/board/view/24356
https://www.acmicpc.net/board/view/91929
먼저 입력은 정점-정점의 간선을 N개 입력받는다.
따라서 2차원 배열을 이용해
정점A에서 시작되는 간선이 K개라면 base[A][0]~base[A][K]로 배열이 있고 각 값은 간선 반대편 정점이다.

입력이 순차적으로 이뤄질것이라는 보장이없다.
따라서 내가 할수있는 가장빠른 순차 삽입 방법인 이중 연결리스트를 써서 이를 해결했다.
리스트를 초기화 후 정점V와 연결된 정점들을(배열에서) 노드에 정렬 삽입 후 노드에서 배열로 다시 저장하는방식으로 구현했다.

*/
typedef struct _Node
{
    int key;
    struct _Node *prev;
    struct _Node *next;
} Node;

Node *head, *tail;

void init_dlist(void)
{
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	head->next = tail;
	head->prev = head;
	tail->next = tail;
	tail->prev = head;
}

void simple_init(void)
{
    head->next = tail;
	head->prev = head;
	tail->next = tail;
	tail->prev = head;
}

int Insert_Node_in_order_of_size(int k)
{
	Node *s;
	Node *i;
	s = (Node*)malloc(sizeof(Node));
	i = (Node*)malloc(sizeof(Node));

	if(head->next == tail)
	{
		i->key = k;
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
			if(s->key > k)
				break;
			s = s->next;
			if(s==tail)
				break;
		}
		i->key = k;
		i->prev = s->prev;
		i->next = s;
		s->prev->next = i;
		s->prev = i;
	}
	return 0; //삽입함
}

void Insert_array_all(int V, Node *p)
{
    int i=0;
	while(p != tail)
	{
		base[V][i] = p->key;
		p=p->next;
        i++;
	}
}

/* 삭제 생략
void delete_all_Nodes(void)
{
	while(head->next != tail)
	{
		head->next=head->next->next;
		free(head->next->prev);
	}
} */

//여기까진 배열을 정렬저장하기위한 함수들

void DFS(int V)
{
    if(visit[V] == 0)
    {
        visit[V]=1;
    for(int i=0;i<count[V];i++)
    {
        int key = base[V][i];
        if(check[key] == 0)
        {
            check[key] = 1;
            printf("%d ", key);
        }
        DFS(key);
        
    }
    }
}

void BFS(int V)
{
    if(visit[V] == 0)
    {
        visit[V] = 1;
    for(int i=0;i<count[V];i++)
    {
        int key = base[V][i];
        if(visit[key] == 0)
            wait[MAX++] = key;
        
        if(check[key] == 0)
        {
            check[key] = 1;
            printf("%d ", key);
        }
    }
    if(P!=MAX)
        BFS(wait[P++]);
    }
}

int main()
{
    //data input
    scanf("%d %d %d", &N, &M, &V);
    int sum = 0;
    int line = 0;
    while(1)
    {
        if(2==M)
            if(sum==N)
                break;
        if(line == M)
            break;
        line++;
        int A, B;
        scanf("%d", &A);
        scanf("%d", &B);
        if(visit[A] == 0) {
            visit[A] = 1;
            sum++;
        }
        if(visit[B] == 0) {
            visit[B] = 1;
            sum++;
        }
        //입력은 간선의 나열일뿐 정렬이 돼있지않다.
        //따라서 2,4가 들어올경우 2[0]=4 , 4[0]=2 같은식으로 각노드에서 인접한 노드를 각각 저장하는식으로 할것이다.
        int count_A = count[A];
        int count_B = count[B];
        if(base[A][count_A] == 0) {
            count[A]++;
            base[A][count_A] = B;
        }
        if(base[B][count_B] == 0) {
            count[B]++;
            base[B][count_B] = A;
        }
    }
    memset(visit, 0, sizeof(int) * 1001);

    //array sort
    init_dlist();
    for(int i=1; i<=N; i++)
    {
        //printf("sort :");
        for(int j=0; j<count[i] ;j++)
        {
            //printf("%d %d, ", i, base[i][j]);
            Insert_Node_in_order_of_size(base[i][j]);
        }
        //delete_all_Nodes() //삭제생략
        //printf("\n");
        Insert_array_all(i, head->next);
        simple_init();
    }

    //array check
    /* printf("\n");
    for(int i=1; i<=N; i++)
    {
        for(int j=0; j<count[i] ;j++)
        {
            printf("%d %d\n", i, base[i][j]);
        }
    } */

    //여기까지가 배열을 입력받아 오름차순으로 정렬

    //DFS
    check[V] = 1;
    printf("%d ", V);
    DFS(V);
    printf("\n");

    //다시 사용할 배열초기화
    memset(visit, 0, sizeof(int) * 1001);
    memset(check, 0, sizeof(int) * 1001);

    //BFS
    check[V] = 1;
    printf("%d ", V);
    BFS(V);
    printf("\n");

    return 0;
}