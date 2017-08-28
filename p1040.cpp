#include <iostream>
#include <set>
#include <vector>
using namespace std;

inline double k(const pair<int, int>& p1, const pair<int, int>& p2) {
    return (p1.second - p2.second) / (p1.first - p2.first);
}

inline bool vertical(const pair<int, int>& p1, const pair<int, int>& p0, const pair<int, int>& p2) {
    return (k(p0, p1) * k(p0,p2) == -1);
}

struct Line {
    int x1, y1, x2, y2;
    double length;
    Line(int _x1, int _y1, int _x2, int _y2) : x1(_x1), y1(_y1), x2(_x2), y2(_y2) {
        if (x1 > x2) {
            int tx, ty;
            tx = x1; ty = y1;
            x1 = x2; y1 = y2;
            x2 = tx; y2 = ty;
        } 
        length = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    }
    bool operator==(Line& r) {
        return ((x1 == r.x1 && y1 == r.y1) || (x1 == r.x2 && y1 == r.y2) || (x2 == r.x1 && y2 == r.y1) || (x2 == r.x2 && y2 == r.y2) );
    }
};

bool vertical(Line& l, Line& r) {
    if (l == r && ) 

             
}

int main(int argc, char const *argv[]) {
    int n, x1, y1, x2, y2;
    cin >> n;
    vector<Line> lines;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> x1 >> y1 >> x2 >> y2;
            Line l(x1, y1, x2, y2);
            lines.push_back(l);
        }
    }
    if ()
    // if (points.size() != 4) {
    //     cout << "NO"<< endl;
    //     return 0;
    // }
    // auto it = points.begin();
    // auto &p1 = *it, &p2 = *(++it), &p3 = *(++it), &p4 = *(++it);
    // if (p1.first == p2.first || p1.first == p3.first || p1.first == p4.first || p2.first == p3.first || p2.first == p4.first || p3.first == p4.first) {
    //     if (p1.first == p2.first) {
    //         if (p3.first == p4.first && )
    //     } else if (p1.first == p3.first) {

    //     } else if (p1.first == p4.first) {

    //     } else {
    //         cout << "NO" << endl;
    //     }
    // } else {
    //     if (vertical(p1,p2,p3) && vertical(p2,p3,p4) && vertical(p3,p4,p1) && vertical(p4,p1,p2)) {
    //         cout << "YES" <<endl;
    //     } else {
    //         cout << "NO" <<endl;
    //     }
    // }
    return 0;
}
