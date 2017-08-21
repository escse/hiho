#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_N = 255;
int n, K;
int a[MAX_N], m[MAX_N];
int dp[MAX_N+1][MAX_N+1];
int dp1[MAX_N+1];

//dp[i+1][j] 用前i数字能否加和得到j
void solve() {
    dp[0][0] = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= K; ++j) {
            for (int k = 0; k <= m[i] && k * a[i] <= j; ++k) {
                dp[i+1][j] |= dp[i][j - k * a[i]];
            }
        }
    }
}

//dp[i+1][j] 用前i数字加和得到j时剩余的i，-1 ???
void solve1() {
    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= K; ++j) {
            if (dp1[j] >= 0) {
                dp1[j] = m[i];
            } else if (j <= a[i] || dp1[j-a[i]] <= 0) {
                dp1[j] = -1;
            } else {
                dp1[j] = dp1[j-a[i]] - 1;
            }
        }
    }
}


int main(int argc, const char *argv[]) {
    
    return 0;
}