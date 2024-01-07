#include <stdio.h>

char v[10] = "AEIOUaeiou";

int main() {
    int TestCase; scanf("%d", &TestCase);
    while(TestCase--) {
        getchar();
        char str[101]; scanf("%[^\n]s", str);
        // printf("%s\n", str);
        char *ptr = str;
        int consonants = 0, vowels = 0;
        while(*ptr != '\0') {
            for(int i=0; i<10; i++) {
                if(*ptr == v[i]) {
                    vowels++;
                    break;
                }
            }
            if(*ptr++ != ' ') consonants++;
        }
        printf("%d %d\n", consonants-vowels, vowels);
    }
    return 0;
}