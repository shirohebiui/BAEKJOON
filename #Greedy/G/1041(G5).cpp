#include <iostream>
using namespace std;
typedef unsigned long u32;
int main() {
    u32 n; cin >> n;
    u32 a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
    u32 s1, s2, s3;
    
    s1 = min(a,b); s1 = min(s1, c); s1 = min(s1, d);
    s1 = min(s1, e); s1 = min(s1, f);

    s2 = min(e, d); s2 = min(s2, b); s2 = min(s2, c); s2 += a;
    s2 = min(s2, f+b); s2 = min(s2, f+c);s2 = min(s2, f+d); s2 = min(s2, f+e);
    s2 = min(s2, e+d);  s2 = min(s2, d+b); s2 = min(s2, c+b); s2 = min(s2, e+c);

    s3 = min(a+d+b, a+d+e); s3 = min(s3, a+e+c); s3 = min(s3, a+b+c);
    s3 = min(s3, f+d+b); s3 = min(s3, f+d+e); s3 = min(s3, f+e+c); s3 = min(s3, f+b+c);
    // cout << s1 << " " << s2 << " " << s3 << endl;
    if(n==1) {
        cout << a+b+c+d+e+f - max(a,max(b,max(c,max(d,max(e,f)))));
    } else if(n==2) {
        cout << s2*4 + s3*4;
    } else {
        cout << s1*((n-2)*(n-2)*5 + (n-2)*4) + s2*(8*(n-2)+4) + s3*4;
    }

    cout << endl;
    return 0;
}