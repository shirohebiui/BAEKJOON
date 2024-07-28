#include <iostream>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)


#include <cstdlib>
#include <deque>
#define MAX 1001
typedef short s16;
struct node {
	s16 key;
	node *left, *right;
};
node G[MAX];

node *Gen(deque<s16> *pre, deque<s16> *in) {
	if(!(pre->size() && in->size())) return NULL;
	s16 root = pre->front(); pre->pop_front();
	deque<s16> new_pre, new_in;
	while(in->size() && root != in->front()) {
		new_pre.push_back(pre->front()); pre->pop_front();
		new_in.push_back(in->front()); in->pop_front();
	}
	in->pop_front();
	G[root].left = Gen(&new_pre, &new_in);
	G[root].right = Gen(pre, in);
	return &G[root];
}

inline void postorder(node *i) {
	if(i->left != NULL) postorder(i->left);
	if(i->right != NULL) postorder(i->right);
	printf("%hd ", i->key);
}

int main() {
	FOR(idx, 1, MAX) G[idx].key = idx;
	int tc; scanf("%d", &tc);
	deque<s16> pre, in;
	s16 input; int n;
	while(tc--) {
		pre.clear(); in.clear();
		scanf(" %hd", &n);
		FOR(i, 0, n) {
			scanf(" %hd", &input);
			pre.push_back(input);
		}
		FOR(i, 0, n) {
			scanf(" %hd", &input);
			in.push_back(input);
		}
		postorder(Gen(&pre, &in)); printf("\n");
	}
    return 0;
}