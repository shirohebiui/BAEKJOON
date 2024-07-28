using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

#include <cstdio>
//**************************base function start*********************************
//READ
constexpr int RSZ = 1<<16;
char rbuf[RSZ], *rbp;
const char *rbp_end = rbuf + RSZ;
inline char ReadChar() {
    if(rbp == rbp_end) fread(rbp = rbuf, sizeof(char), RSZ, stdin);
    return *rbp++;
}
inline int ReadInt() {
    int ret = 0;
    for (char c = ReadChar(); c&16; ret = ret*10 + (c&15), c = ReadChar());
    return ret;
}
//WRITE
constexpr int WSZ = 1<<16;
char wbuf[WSZ]; int wbp;
const int wbp_end = WSZ - 30;

inline void wbuf_flush() {
    fwrite(wbuf, 1, wbp, stdout);
    wbp = 0;
}

inline void wbuf_write(char *p) {
    while(*p != '\0') wbuf[wbp++] = *p++;
	wbuf[wbp++] = ' ';
    if(wbp > wbp_end) wbuf_flush();
}

//itoa
#define RADIX 10
char output[11], output_tmp[11], *tmp;
inline char *itoa(int input) {
    if(input == 0) {*output = '0'; *(output+1) = '\0'; return output;} //0일경우 예외처리

    tmp = output_tmp+1;
    if(input < 0) {input ^= 1<<31; *tmp++ = '-';} //음수처리

    //itoa func
    while(input) {
        *tmp++ = '0' + input%RADIX;
        input /= RADIX;
    } tmp--;
    char *p = output; //output pointer
    while(*tmp != '\0') *p++ = *tmp--;
    *p = '\0';
    return output;
}
//**************************base function end************************************
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
    post.erase(post.begin() + end);

    int center = 0;
    while(now->key != in[center]) ++center;
    in.erase(in.begin() + center);
    now->left = Gen(center-1);
    now->right = Gen(end-center-1);
    return now;
}

void preorder(node *i) {
	wbuf_write(itoa(i->key));
    if(i->left != NULL) preorder(i->left);
    if(i->right != NULL) preorder(i->right);
}

int main() {
    FOR(idx, 1, MAX) G[idx].key = idx;
	fread(rbp = rbuf, sizeof(char), RSZ, stdin);
    int n = ReadInt(), input;
    FOR(i, 0, n) in.push_back(ReadInt());
    FOR(i, 0, n) post.push_back(ReadInt());
    preorder(Gen(n-1)); wbuf[wbp] = '\n';
	fwrite(wbuf, sizeof(char), wbp, stdout);
    return 0;
}