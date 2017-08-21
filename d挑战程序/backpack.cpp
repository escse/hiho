#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 255

int n, W;
int w[MAX_N], v[MAX_N];
int dp[MAX_N+1][MAX_N+1];
int dp1[MAX_N+1];
// 前i个物品中总重不超过j
void solve() {
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= W; ++j) {
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if (j + w[i] <= W) {
                dp[i+1][j+w[i]] = max(dp[i+1][j+w[i]], dp[i][j] + v[i]);
            }
        }
    }
}


void solve_perfect() {
    for (int i = 0; i <= n; ++i) {
        for (int j = W; j >= w[i]; --j) {
            dp1[j] = max(dp1[j], dp1[j-w[i]] + v[i]);
        }
    }
}

void solve_full() {
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= W; ++j) {
            if (j < w[i]) {
                dp[i+1][j] = dp[i][j];
            } else {
                dp[i+1][j] = max(dp[i+1][j], dp[i+1][j-w[i]] + v[i]);
            }
        }          
    }
}

void solve_full_perfect() {
    for (int i = 0; i <= n; ++i) {
        for (int j = w[i]; j <= W; ++j) {
            dp1[j] = max(dp1[j], dp1[j-w[i]] + v[i]);
        }
    }
}
// 刚好只是方向相反

// 如果W很大，改变i， j的意义，从value 出发
int main(int argc, const char *argv[]) {
    return 0;
}