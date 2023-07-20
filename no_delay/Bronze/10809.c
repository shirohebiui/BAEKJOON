#include <stdio.h>
char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
                'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int main()
{
    char word[101];
    scanf("%s", word);

    char count[26]= {0, };
    char *ptr = word;
    int place=1;
    while(*ptr != NULL) {
        for(int i=0;i<26;i++) {
            if(*ptr == alpha[i] && count[i] == 0)
                count[i] = place;
        }
        ptr++; place++;
    }
    for(int i=0;i<26;i++) {
        printf("%d ", count[i]-1);
    }
    printf("\n");

    return 0;
}