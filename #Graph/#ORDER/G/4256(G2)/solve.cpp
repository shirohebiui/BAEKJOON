#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)


typedef short s16;
#include <cstdlib>
#define MAX 1001
struct node {
	s16 key;
	node *left, *right;
};
node G[MAX];
#include <vector>
vector<s16> pre, in;
bool vis[MAX];

node *Gen(s16 start, s16 end) {
	if(end == 0) return NULL;
	// printf("\nstart %d, end %d", start, end);
	// //test
	// printf("\npreorder : ");
	// FOR(i, start, end) printf("%d ", pre[i]);
	// printf("\ninorder  : ");
	// FOR(i, start, end) printf("%d ", in[i]);

	s16 now = pre[0];
	pre.erase(pre.begin());
	s16 center = start;
	while(now != in[center]) ++center;
	// printf("\ncetenr %d < end %d", center, end); fflush(stdout);
	// printf("\n\n\n");
	in.erase(in.begin() + center);
	// printf("\nstart %d : end %d : center : %d", start, end, center);
	// printf("\nerase %d", in[center]);
	G[now].left = Gen(start, center);
	// if(G[now].left) printf("\nleft %d -> %d",now, G[now].left->key);
	G[now].right = Gen(0, end-center-1);
	// if(G[now].right) printf("\nright %d -> %d",now, G[now].right->key);
	return &G[now];
}

void postorder(node *i) {
	if(i->left != NULL) postorder(i->left);
	if(i->right != NULL) postorder(i->right);
	printf("%hd ", i->key);
}
void G_print(int k) {
	printf("node : %d", k);
	if(G[k].left) printf(" left[%d]", G[k].left->key);
	if(G[k].right) printf(" right[%d]", G[k].right->key);
	printf("\n");
}
int main() {
	FOR(idx, 1, MAX) G[idx].key = idx;
	int tc; scanf(" %d", &tc);
	while(tc--) {
		s16 n; scanf(" %hd", &n);
		s16 input;
		FOR(i, 0, n) {scanf(" %hd", &input); pre.push_back(input);}
		FOR(i, 0, n) {scanf(" %hd", &input); in.push_back(input);}

		postorder(Gen(0, n)); printf("\n");
	}
	// FOR(i, 0, n) G_print(i);
    return 0;
}