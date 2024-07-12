#include <cstdio>
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

//READ
//4194314
constexpr int RSZ = 1<<18;
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

//itoa
char output[11], output_tmp[11], *tmp;
inline char *itoa(int input, int radix) {
    if(input == 0) {*output = '0'; *(output+1) = '\0'; return output;} //0일경우 예외처리

    tmp = output_tmp+1;
    if(input < 0) {input ^= 1<<31; *tmp++ = '-';} //음수처리

    //itoa func
    while(input) {
        *tmp++ = '0' + input%radix;
        input /= radix;
    } tmp--;
    char *p = output; //output pointer
    while(*tmp != '\0') *p++ = *tmp--;
    *p = '\0';
    return output;
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
    wbuf[wbp++] = '\n';
    if(wbp > wbp_end) wbuf_flush();
}


int arr[1025][1025];
int main() {
    fread(rbp = rbuf, sizeof(char), RSZ, stdin);
    int n = ReadInt(), m = ReadInt();
    FOR(i, 1, n+1) {
        FOR(j, 1, n+1) {
            arr[i][j] += arr[i][j-1] + arr[i-1][j] - arr[i-1][j-1] + ReadInt();
        }
    }
    int y1, x1 ,y2 ,x2;
    FOR(i, 0, m) {
        y1 = ReadInt(), x1 = ReadInt(), y2 = ReadInt(), x2 = ReadInt();
        wbuf_write(itoa(arr[y1-1][x1-1] + arr[y2][x2] - arr[y1-1][x2] - arr[y2][x1-1], 10));
    }
    wbuf_flush();
    return 0;
}