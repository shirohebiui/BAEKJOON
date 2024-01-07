#include <stdio.h>
#include <stdlib.h>

typedef struct human{
    int h;
    int w;
}human;

human arr[51];
int ranking[51];

int main() {
    int N; scanf("%d", &N);
    for(int i=0; i<N; i++) scanf(" %d %d", &arr[i].w, &arr[i].h);

    for(int i=0; i<N; i++) {
        human *s = &arr[i];
        for(int j=0; j<N; j++) {
            if(i == j) continue;
            else if(s->h < arr[j].h && s->w < arr[j].w) {
                ranking[i]++;
            }
        }
    }
    for(int i=0; i<N; i++) printf("%d ", ranking[i]+1);
    printf("\n");
    return 0;
}