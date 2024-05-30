#include <iostream>
using namespace std;
#define ALL 0b111111111111111111111
#include <string.h>
int s;
void func(char *cmd) {
    if(!strcmp(cmd, "all")) {
        s = ALL;
        return;
    } else if(!strcmp(cmd, "empty")) {
        s = 0;
        return;
    }
    int x; cin >> x;
    if(!strcmp(cmd, "add")) {
        s |= 1<<x;
    } else if(!strcmp(cmd, "remove")) {
        s &= ALL ^ (1<<x);
    } else if(!strcmp(cmd, "check")) {
        cout << (s>>x & 1 ? 1 : 0) << "\n";
    } else {//if(!strcmp(cmd, "toggle")) {
        int tmp = s | (1<<x);
        if(tmp == s) s &= ALL ^ (1<<x);
        else s = tmp;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    int m; cin >> m;
    char cmd[7]; 
    while(m--) {
        cin >> cmd;
        func(cmd);
    }
    return 0;
}