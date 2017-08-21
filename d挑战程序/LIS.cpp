#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;
#define MAX_N 255

int n;
int a[MAX_N];
int dp[MAX_N];

//dp[i]=以a[i]为末尾的最长上升子序列长度
void solve() {
    int res = 0;
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }
}

//dp[i]=长度为i+1的上升子序列中末尾元素最小值 ???
void solve1() {
    fill(dp, dp+n, numeric_limits<int>::max());
    for (int i = 0; i < n; ++i) {
        *lower_bound(dp, dp+n, a[i]) = a[i];
    }
}

int main(int argc, const char *argv[]) {

    return 0;
}