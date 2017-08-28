#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


// In file included from /usr/include/c++/4.8/algorithm:62:0,
// from /1109276.28251/Main.cc:4:
// /usr/include/c++/4.8/bits/stl_algo.h: In instantiation of ‘_RandomAccessIterator std::__unguarded_partition(_RandomAccessIterator, _RandomAccessIterator, const _Tp&) [with _RandomAccessIterator = __gnu_cxx::__normal_iterator<p*, std::vector<p> >; _Tp = p]’:
// /usr/include/c++/4.8/bits/stl_algo.h:2283:70: required from ‘_RandomAccessIterator std::__unguarded_partition_pivot(_RandomAccessIterator, _RandomAccessIterator) [with _RandomAccessIterator = __gnu_cxx::__normal_iterator<p*, std::vector<p> >]’
// /usr/include/c++/4.8/bits/stl_algo.h:2315:54: required from ‘void std::__introsort_loop(_RandomAccessIterator, _RandomAccessIterator, _Size) [with _RandomAccessIterator = __gnu_cxx::__normal_iterator<p*, std::vector<p> >; _Size = long int]’
// /usr/include/c++/4.8/bits/stl_algo.h:5461:36: required from ‘void std::sort(_RAIter, _RAIter) [with _RAIter = __gnu_cxx::__normal_iterator<p*, std::vector<p> >]’
// /1109276.28251/Main.cc:37:30: required from here
// /usr/include/c++/4.8/bits/stl_algo.h:2245:19: error: passing ‘const p’ as ‘this’ argument of ‘bool p::operator<(const p&)’ discards qualifiers [-fpermissive]
// while (__pivot < *__last)
// ^

enum Type{
    IN_GREEN, IN_BLUE, OUT_GREEN, OUT_BLUE
};

struct p {
    int x;
    Type t;
    p(int _x, Type _t) : x(_x), t(_t) {}
    // bool operator<(const p& rhs){return x<rhs.x;}
};

typedef vector<p> points;


int main(int argc, char const *argv[]) {
    int m, n;
    int l, r;
    points ps;
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        cin >> l >> r;
        ps.push_back(p(l, IN_GREEN));
        ps.push_back(p(r, IN_BLUE));
    }
    for (int i = 0; i < n; ++i) {
        cin >> l >> r;
        ps.push_back(p(l, OUT_GREEN));
        ps.push_back(p(r, OUT_BLUE));
    }
    sort(ps.begin(), ps.end());
    int in_cnt = 0;
    int out_cnt = 0;
    int length = 0;
    int last = -100000;
    for (auto& p:ps) {
        if (in_cnt > 0 && out_cnt == 0) length += (p.x-last);
        switch(p.t) {
            case IN_GREEN:
                ++in_cnt;
                break;
            case IN_BLUE:
                --in_cnt;
                break;
            case OUT_GREEN:
                ++out_cnt;
                break;
            case OUT_BLUE:
                --out_cnt;
                break;
        }
        last = p.x;
    }
    cout << length << endl;
    return 0;
}