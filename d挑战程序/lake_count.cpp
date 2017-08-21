#include <iostream>
using namespace std;
#define MAX_N 255

int N, M;
char filed[MAX_N][MAX_N];

void dfs(int x, int y) {
    filed[x][y] = '.';
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            int nx = x + dx;
            int ny = y + dy;
            if (0 <= nx && nx < N && 0 <= ny && ny < M && filed[nx][ny] == 'W') {
                dfs(nx, ny);
            }
        }
    }
}

int main(int argc, const char *argv[]) {
    int res = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (filed[i][j] == 'W') {
                dfs(i, j);
                ++res;
            }
        }
    }
    return 0;
}