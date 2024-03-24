#include <stdio.h>
#include <queue>
using namespace std;

int vis[100001];
int start_point, end_point;
void bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(start_point, 0));
	while(!q.empty()){
		int x = q.front().first;
		int time = q.front().second;
        int tmp;
		q.pop();
		vis[x] = 1;
        if(x == end_point) {
            printf("%d\n", time); return;
        }
        tmp = x * 2;
        if(tmp <= 100000 && !vis[tmp]) {
            while(tmp <= 100000) {
                if(!vis[tmp]) q.push(make_pair(tmp,time));
                tmp *= 2;
            }
        }
        tmp = x - 1;
		if(tmp>=0 && !vis[tmp]) q.push(make_pair(tmp,time+1));
        tmp = x + 1;
		if(tmp<=100000 && !vis[tmp]) q.push(make_pair(tmp,time+1));
	}
}

int main(){
	scanf(" %d %d", &start_point, &end_point);
	bfs();
	return 0;
}