#include <stdio.h>
#include <string.h>

char func[100001];
char arr[100001];
int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        //input
        int cnt; scanf("%s %d", func, &cnt);
        // printf("%s %d\n", func, cnt);
        int idx = 0; getchar();getchar();
        while(cnt--) {
            char in; scanf("%hhd", &in);
            arr[idx++] = in;
            char tmp = getchar();
            if(tmp == ']') break;
        }
        getchar();
        //func
        int mod = 1;
        int start = 0, end = idx;
        // printf("s %d e %d\n", start, end);
        int s = start, e = end;
        for(int i=0; i<strlen(func); i++) {
            if(func[i] == 'R') {
                mod = -mod;
            } else {
                if(mod > 0) start++;
                else        end--;
            }
        }
        if(start < end) {
            end--;
                printf("[");
            if(mod > 0) {
                while(start<end) printf("%d,", arr[start++]);
                printf("%d", arr[end]);
            } else {
                while(start<end) printf("%d,", arr[end--]);
                printf("%d", arr[start]);
            }
                printf("]\n");
        } else if(start == end) {
            printf("[]\n");
        } else{
            printf("error\n");
        }
    }
}