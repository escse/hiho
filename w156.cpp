#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 50;
bool visited[MAX][MAX];
char grid[MAX][MAX];
int delta[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};


int dfs(int _x, int _y, int _sx, int _sy, vector<pair<char, char> >& shape) {
    visited[_x][_y] = true;
    int cnt = 1;
    shape.push_back({_x-_sx, _y-_sy});
    for (int i = 0; i < 4; ++i) {
        int x = _x + delta[i][0];
        int y = _y + delta[i][1];
        if ((x < MAX && x >= 0) && (y < MAX && y >= 0) && !visited[x][y] && grid[x][y] == '#') {
            cnt += dfs(x, y, _sx, _sy, shape);
        }
    }
    return cnt;
}

int main(int argc, char const *argv[]) {
    memset(visited, 0, sizeof(visited));
    int m, n;
    cin >> m  >> n;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    int cnt = 0;
    set<int> c;
    // set<string> shape;
    vector<pair<char, char>> shape;
    set<decltype(shape)> shapes;
    for (int x = 0; x < m; ++x) {
        for (int y = 0; y < n; ++y) {
            if (!visited[x][y] && grid[x][y] == '#') {
                shape.clear();
                c.insert(dfs(x, y, x, y, shape));
                ++cnt;
                // sort(shape.begin(), shape.end());
                shapes.insert(shape);
            }
        }
    }
    cout << cnt << " " << c.size() << " " << shapes.size();
    return 0;
}