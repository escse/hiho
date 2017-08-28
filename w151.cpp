#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <cstring>
using namespace std;
const int MAX = 102;

int exist[MAX][MAX][MAX];
int outside[MAX][MAX][MAX];


struct Point {
    int x, y, z;
    Point() {}
    Point(int _x, int _y, int _z): x(_x), y(_y), z(_z){}
    bool invalid() {
        return x < 0 || x >= MAX-1 || y < 0 || y >= MAX-1 || z < 1 || z >= MAX-1;
    }
};




bool adjacent(const Point& p) {
    if (exist[p.x][p.y][p.z]) return false;
    if (p.z == 1) return true;
    return exist[p.x - 1][p.y][p.z] || exist[p.x + 1][p.y][p.z] ||
           exist[p.x][p.y - 1][p.z] || exist[p.x][p.y + 1][p.z] ||
           exist[p.x][p.y][p.z - 1] || exist[p.x][p.y][p.z + 1];
}

bool isoutside(Point& p) {
    int x = p.x, y = p.y, z = p.z;
    return  outside[x - 1][y][z] ||
            outside[x + 1][y][z] ||
            outside[x][y - 1][z] ||
            outside[x][y + 1][z] ||
            outside[x][y][z - 1] ||
            outside[x][y][z + 1];
}

void floodfill(Point& p) {
    vector<Point> fill;
    int x, y, z;
    fill.push_back(p);
    while (!fill.empty()) {
        Point pp = fill.back();
        x = pp.x; y = pp.y; z = pp.z;
        fill.pop_back();
        if (pp.invalid() || outside[x][y][z] || exist[x][y][z]) continue;
        outside[x][y][z] = true;
        fill.push_back(Point(x+1, y, z));
        fill.push_back(Point(x-1, y, z));
        fill.push_back(Point(x, y+1, z));
        fill.push_back(Point(x, y-1, z));
        fill.push_back(Point(x, y, z+1));
        fill.push_back(Point(x, y, z-1));
    }
}

int main(int argc, char const *argv[]) {
    int n, m, x, y, z;
    vector<Point> points;
    scanf("%d", &n);
    while (n--) {
        points.clear();
        scanf("%d", &m);
        memset(exist, 0, sizeof(exist));
        memset(outside, 0, sizeof(outside));
        Point p;
        bool stop = false;
        while (m--) {
            scanf("%d%d%d",&p.x, &p.y, &p.z);
            if (!adjacent(p) && !stop) {
                printf("No\n"); 
                stop = true;
            }
            if (!stop) {
                points.push_back(p);
                exist[p.x][p.y][p.z] = true;
            }
        }
        if (stop) continue;
        for (int i = 0; i < MAX; ++i)
            for (int j = 0; j < MAX; ++j)
                exist[i][j][0] = true;
        Point pmax(MAX-2, MAX-2, MAX-2);
        floodfill(pmax);
        while (!points.empty()) {
            Point p = points.back();
            points.pop_back();
            if (isoutside(p)) {
                exist[p.x][p.y][p.z] = false;
                floodfill(p);
            } else {
                printf("No\n");
                stop = true;
                break;
            }
        }
        if (stop) continue;
        printf("Yes\n");
    }
    return 0;
}


