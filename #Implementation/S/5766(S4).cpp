#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 10000
typedef struct ranker{
    int idx;
    short prio;
}ranker;
vector<ranker> v(MAX+1);
short prio_rank[MAX+1];

bool cmp(const ranker &s1, const ranker &s2) {
    if(s1.prio < s2.prio) return 1;
    if(s1.prio == s2.prio && s1.idx > s2.idx) return 1;
    return 0;
}


int main(){
    ranker r;
    int k, n, m, best, size;
    while(1) {
        //input
        cin >> n >> m;
        size = n*m;
        if(!size) return 0;

        //init
        v.clear();
        k = MAX+1;
        while(k--) prio_rank[k] = 0;

        //func

        //setting prio of idx
        k = size;
        while(k--) {
            int idx; cin >> idx;
            prio_rank[idx]++;
        }

        //insert vector pair [idx-prio]
        k = MAX+1;
        best = 0;
        while(k--) {
            if(prio_rank[k] == 0) continue;
            r.prio = prio_rank[k];
            r.idx = k;
            v.push_back(r);
        }

        //sorting 1.prio 2.idx
        sort(v.begin(), v.end(), cmp);

        //print second rank
        k = v.end()-v.begin()-1;
        best = v[k].prio;
        while(v[k].prio == best) {
            k--;
        }
        best = v[k].prio;
        while(k>=0 && v[k].prio == best) {
            cout << v[k].idx << " ";
            k--;
        }
        cout << endl;
    }
    return 0;
}