#include <iostream>
#include <algorithm>
#include <cstring>
//提交系统这题有问题
/*
#include<bits/stdc++.h>这个头文件包含以下等等C++中包含的所有头文件： 
#include <iostream> 
#include <cstdio> 
#include <fstream> 
#include <algorithm> 
#include <cmath> 
#include <deque> 
#include <vector> 
#include <queue> 
#include <string> 
#include <cstring> 
#include <map> 
#include <stack> 
#include <set> 
*/
using namespace std;
const int MIN = -10000;
int bonus[101][101];
int dp[101][101];


int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    memset(bonus, 0, sizeof(bonus));
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> bonus[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        bonus[i][0] = MIN;
    }
    dp[1][1] = bonus[1][1];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i][j] =  bonus[i][j] + max(dp[i-1][j], dp[i - 1][j - 1]);
        }
    }
    sort(dp[n]+1, dp[n]+n+1);
    cout << dp[n][n] << endl;
    return 0;
}
