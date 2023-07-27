#include <stdio.h>

int main() {
    char arr[5];
    fgets(arr, 6, stdin);
    printf("%s\n", arr);
    fgets(arr, 6, stdin);
    printf("%s\n", arr);
}