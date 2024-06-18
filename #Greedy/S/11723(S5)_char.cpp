#include <iostream>
using namespace std;

#include <algorithm>
#include <string.h>
char s[21];
void func(char *cmd) {
    if(!strcmp(cmd, "all")) {
        memset(s, 0x01, 21);
        return;
    } else if(!strcmp(cmd, "empty")) {
        memset(s, 0x00, 21);
        return;
    }
    int x; cin >> x;
    if(!strcmp(cmd, "add")) {
        s[x] = 1;
    } else if(!strcmp(cmd, "remove")) {
        s[x] = 0;
    } else if(!strcmp(cmd, "check")) {
        cout << (s[x] ? 1 : 0) << "\n";
    } else {//if(!strcmp(cmd, "toggle")) {
        s[x] = s[x] ? 0 : 1;
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