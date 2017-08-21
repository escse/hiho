#include <iostream>
using namespace std;
#define MAX_N 255

int a[MAX_N];
int n, k;

bool dfs(int i, int sum) {
    if (i == n) return sum == k;
    if (dfs(i + 1, sum)) return true;
    if (dfs(i + 1, sum + a[i])) return true;
    return false;
}

int main(int argc, const char *argv[]) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> k;
    if (dfs(0, 0)) cout << "YES";
    else cout << "NO";
    return 0;
}