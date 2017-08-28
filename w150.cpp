#include <cstdio>
#include <cstring>
// using namespace std;

int grids[102][102][2];
unsigned int blocks[102][102];
const int MAX = 10000;
inline int min(int a, int b, int c, int d) {
    int tmp1 = a < b ? a : b;
    int tmp2 = c < d ? c : d;
    return tmp1 < tmp2 ? tmp1 : tmp2;
}

int solve(int i, int j, int d) {
    if (i == 0 || j == 0) return MAX;
    if (grids[i][j][d] != -1) return grids[i][j][d];
    if (d == 0) {
        // left =>
        int a = solve(i, j - 1, d) + blocks[i][j];
        // left 向下
        int b = solve(i, j - 1, !d) + blocks[i][j] + !blocks[i + 1][j - 1];
        // up  =>
        int c = solve(i - 1, j, d) + blocks[i][j] + !blocks[i - 1][j + 1] + !blocks[i + 1][j];
        // up 向下
        int dd = solve(i - 1, j, !d) + blocks[i][j] + !blocks[i + 1][j];
        
        grids[i][j][d] = min(a, b, c, dd);
    } else {
        // left =>
        int a = solve(i, j - 1, !d) + blocks[i][j] + !blocks[i][j + 1];
        // left 向下
        int b = solve(i, j - 1, d) + blocks[i][j] + !blocks[i + 1][j - 1] + !blocks[i][j + 1];
        // up  =>
        int c = solve(i - 1, j, !d) + blocks[i][j] + !blocks[i -1][j + 1];
        // up 向下
        int dd = solve(i - 1, j, d) + blocks[i][j];
        
        grids[i][j][d] = min(a, b, c, dd);
    }
    return grids[i][j][d];
}

int main(int argc, char const *argv[]) {
    memset(grids, -1, sizeof(grids));
    int m, n;
    char buffer[256];
    scanf("%d%d",&m, &n);
    for (int i = 1; i <= m; ++i) {
        scanf("%s", buffer);
        for (int j = 1; j <= n; ++j) {
            blocks[i][j] = buffer[j - 1] == 'b';
        }
    }
    for (int i = 0; i <= m + 1; ++i) {
        blocks[i][0] = 1; blocks[i][n + 1] = 1;
        grids[i][0][0] = 0; grids[i][0][1] = 0;
    }
    for (int i = 0; i <= n + 1; ++i) {
        blocks[0][i] = 1; blocks[n + 1][i] = 1;
        grids[0][i][0] = MAX; grids[0][i][1] = MAX;
    }
    grids[1][1][0] = 0;
    grids[1][1][1] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int a = solve(i, j, 0);
            int b = solve(i, j, 1);
        }
    }
    int a = solve(m, n, 0);
    int b = solve(m, n, 1);
    printf("%d\n", a < b ? a: b);
    return 0;
}