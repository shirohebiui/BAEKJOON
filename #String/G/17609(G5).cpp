#include <iostream>
using namespace std;

int isPalind(bool flag, char *head, char *tail) {
    while(head < tail) {
        if(*head == *tail) {
            ++head; --tail;
        } else if(flag == 0) {
            return 1 + (isPalind(1, head+1, tail) && isPalind(1, head, tail-1));
        } else {
            return 1;
        }
    }
    return 0;
}

#include <cstring>
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc; cin >> tc;
    while(tc--) {
        char str[100001]; cin >> str;
        cout << isPalind(0, str, str+strlen(str)-1) << "\n";
    }

    return 0;
}