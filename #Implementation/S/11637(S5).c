#include <stdio.h>

int vote[10];
int sum, maxvote, maxperson;

int main() {
    int TestCase; scanf("%d", &TestCase);
    while(TestCase--) {
        int n; scanf(" %d", &n);
        sum = maxvote = maxperson = 0;
        for(int i=0; i<n; i++) {
            scanf(" %d", &vote[i]);
            sum += vote[i];
        }
        for(int i=0; i<n; i++) {
            if(maxvote < vote[i]) {
                maxperson = i;
                maxvote = vote[i];
            } else if(maxvote == vote[i]) {
                maxperson = -1;
            }
        }
        if(maxperson == -1) {
            printf("no winner\n");
        } else {
            if(maxvote >= sum/2 + 1) {
                printf("majority winner %d\n", maxperson+1);
            } else {
                printf("minority winner %d\n", maxperson+1);
            }
        }
    }
    return 0;
}