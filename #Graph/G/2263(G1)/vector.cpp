using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

#include <cstdio>
#include <vector>
#define MAX 100001
struct node {
    int key;
    node *left, *right;
};
node G[MAX];
vector<int> in, post;

node *Gen(int end) {
    if(end < 0) return NULL;

    node *now = &G[post[end]];
	// printf("root %d\n", now->key);
	// printf("end %d\n", *(post.begin() + end));
    post.erase(post.begin() + end);

    int center = 0;
    while(now->key != in[center]) ++center;
    in.erase(in.begin() + center);
	// printf("left\n");
	// FOR(i, 0, center) {
	// 	printf("%d ", in[i]);
	// }
	// printf("\n------\n");
	// printf("right\n");
	// FOR(i, center, end) {
	// 	printf("%d ", in[i]);
	// }
	// printf("\n------\n");
	// printf("%d %d %d\n", end, center, end-center);
    now->left = Gen(center-1);
    now->right = Gen(end-center-1);
    return now;
}

void preorder(node *i) {
    printf("%d ", i->key);
    if(i->left != NULL) preorder(i->left);
    if(i->right != NULL) preorder(i->right);
}

int main() {
    FOR(idx, 1, MAX) G[idx].key = idx;
    int n, input; scanf("%d", &n);
    FOR(i, 0, n) {scanf(" %d", &input); in.push_back(input);}
    FOR(i, 0, n) {scanf(" %d", &input); post.push_back(input);}
    preorder(Gen(n-1)); printf("\n");
    return 0;
}