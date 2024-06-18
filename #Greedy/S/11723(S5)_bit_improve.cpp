#include <iostream>
using namespace std;

#include <string.h>
int s;
void func(char *cmd) {
    if(!strcmp(cmd, "all")) {
        s = ~0;
        return;
    } else if(!strcmp(cmd, "empty")) {
        s = 0;
        return;
    }
    int x; cin >> x;
    if(!strcmp(cmd, "add")) {
        s |= 1<<x;
    } else if(!strcmp(cmd, "remove")) {
        s &= ~(1<<x);
    } else if(!strcmp(cmd, "check")) {
        cout << (s>>x & 1 ? 1 : 0) << "\n";
    } else {//if(!strcmp(cmd, "toggle")) {
        int tmp = s | (1<<x);
        (tmp == s ? (s &= ~(1<<x)) : (s = tmp));
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