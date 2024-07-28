#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

#include <cstdlib>
#include <deque>
#define MAX 100001
struct node {
	int key;
	node *left, *right;
};
node G[MAX];

node *Gen(deque<int> *in, deque<int> *post) {
	if(!(in->size() && post->size())) return NULL;
	int root = post->back(); post->pop_back();
	deque<int> new_in, new_post;
	while(in->size() && root != in->front()) {
		new_in.push_back(in->front()); in->pop_front();
		new_post.push_back(post->front());post->pop_front();
	}
	in->pop_front();
	G[root].left = Gen(&new_in, &new_post);
	G[root].right = Gen(in, post);
	return &G[root];
}

inline void preorder(node *i) {
	printf("%d ", i->key);
	if(i->left != NULL) preorder(i->left);
	if(i->right != NULL) preorder(i->right);
}

int main() {
	FOR(idx, 1, MAX) G[idx].key = idx;
	deque<int> in, post;
	int input, n;
	scanf(" %d", &n);
	FOR(i, 0, n) {
		scanf(" %d", &input);
		in.push_back(input);
	}
	FOR(i, 0, n) {
		scanf(" %d", &input);
		post.push_back(input);
	}
	preorder(Gen(&in, &post)); printf("\n");
    return 0;
}