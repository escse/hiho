#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <climits>  
using namespace std;  

const int maxn = 111001;  
int n , m;  
int need[maxn] , val[maxn] , dp[maxn];  
  
int main() {  
    // freopen("in.txt" , "r" , stdin);
    while (cin >> n >> m) {
        memset(dp , 0 , sizeof(dp));  
        for (int i = 1 ; i <= n ; i ++)  
            cin >> need[i] >> val[i];  
        for (int i = 1 ; i <= n ; i ++) {
            for(int j = m ; j >= need[i] ; j --) {
                dp[j] = max(dp[j] , dp[j-need[i]] + val[i]);  
            }  
        }  
        cout << dp[m] << endl;
    }
}