#include <cstdio>
long res[101];
int mod = 1000000007;

int get2n(int n) {
    long r = 1;
    for (int i = 0; i < n; ++i) {
        r = (2 * r) % mod;
    }
    return r;
}

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    res[1] = 0;
    res[2] = 1;
    for (int i = 3; i <= n ; ++i) {
        res[i] = (res[i-1] + res[i-2] + get2n(i-2)) % mod;
    }
    printf("%d",res[n]);
    return 0;
}