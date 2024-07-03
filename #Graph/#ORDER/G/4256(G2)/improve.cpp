using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

#include <cstdio>
#include <vector>
#define MAX 1001
typedef short s16;
struct node {
    s16 key;
    node *left, *right;
};
node G[MAX];
vector<s16> pre, in;

node *Gen(s16 end) {
    if(end == 0) return NULL;

    node *now = &G[pre[0]];
    pre.erase(pre.begin());

    s16 center = 0;
    while(now->key != in[center]) ++center;
    in.erase(in.begin() + center);

    now->left = Gen(center);
    now->right = Gen(end-center-1);
    return now;
}

void postorder(node *i) {
    if(i->left != NULL) postorder(i->left);
    if(i->right != NULL) postorder(i->right);
    printf("%hd ", i->key);
}

int main() {
    FOR(idx, 1, MAX) G[idx].key = idx;
    int tc, n; scanf(" %d", &tc);
    s16 input;
    while(tc--) {
        scanf(" %d", &n);
        FOR(i, 0, n) {scanf(" %hd", &input); pre.push_back(input);}
        FOR(i, 0, n) {scanf(" %hd", &input); in.push_back(input);}

        postorder(Gen((s16)n)); printf("\n");
    }
    return 0;
}