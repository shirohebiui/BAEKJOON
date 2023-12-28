#include <stdio.h>

int main() {
    char tmp;
    int h1, m1, s1; scanf("%2d", &h1); scanf("%c", &tmp); scanf("%2d", &m1); scanf("%c", &tmp); scanf("%2d", &s1);
    int h2, m2, s2; scanf(" %2d", &h2); scanf("%c", &tmp); scanf("%2d", &m2); scanf("%c", &tmp); scanf("%2d", &s2);
    // printf("%d:%d:%d\n", h1, m1, s1);
    // printf("%d:%d:%d\n", h2, m2, s2);
    int h3, m3, s3;
    if(s1>s2) {
        s3 = 60-s1+s2; m1++;
    } else      s3 = s2-s1;

    if(m1>m2) {
        m3 = 60-m1+m2; h1++;
    } else      m3 = m2-m1;

    if(h1>h2) h3 = 24-h1+h2;
    else      h3 = h2-h1;

    if(h3 == 0 && m3 == 0 && s3 == 0) h3=24;
    char hour[3] = {h3/10 +'0', h3%10+'0',};
    char min[3] = {m3/10+'0', m3%10+'0',};
    char sec[3] = {s3/10+'0', s3%10+'0',};
    printf("%s:%s:%s", hour, min, sec);
    return 0;
}