#include <stdio.h>

char text[2000];
char output[2000]; int rear;

int main() {
    //input
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf(" %c", &text[i]);
    
    //insert
    int front = 0, back = N-1;
    while(front <= back) {
        if(text[front] < text[back]) output[rear++] = text[front++];
        else if(text[front] > text[back]) output[rear++] = text[back--];
        else {
            int f=front+1, b=back-1;
            while(f<=b) {
                if(text[f]<text[b]) {
                    output[rear++] = text[front++];
                    break;
                } else if(text[f]>text[b]) {
                    output[rear++] = text[back--];
                    break;
                }
                f++; b--;
            }
            if(f>b) {
                output[rear++] = text[front++];
            }
        }
    }

    //answer
    for(int i=0; i<N; i++) {
        printf("%c", output[i]);
        if((i+1)%80 == 0) printf("\n");
    }
    return 0;
}