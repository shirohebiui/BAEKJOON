#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n; //최대값
    char *str = NULL;
    scanf("%d", &n);
    str = (char *)malloc(n);
    scanf("%s", str);
    int count = 0;

    while(str != NULL)
    {
        str = strstr(str, "pPAp");
        if(str!=NULL)
        {
            str+=4;
            count++;
        }
    }
    printf("%d\n", count);
    free(str);
    return 0;
}