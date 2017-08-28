#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


int main(int argc, char const *argv[]) {
    int n,s,e; 
    scanf("%d", &n);
    typedef pair<int, int> T;
    vector<T> p;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d",&s,&e);
        p.push_back({s,1});
        p.push_back({e,-1});
    }
    sort(p.begin(), p.end());
    int maxVal = 0;
    int val = 0;
    for (int i = 0; i < 2*n; ++i) {
        val += p[i].second;
        maxVal = max(val, maxVal);
    }
    printf("%d", maxVal);
    return 0;
}