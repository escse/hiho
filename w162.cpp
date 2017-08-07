#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int res[101][101];

int f(const char *s, int i, int j) {
    if (res[i][j] != -1) return res[i][j];
    if (j - i <= 0) return 0;
    if (s[i] == s[j]) return f(s, i+1, j-1);
    int a = f(s, i+1, j);
    int b = f(s, i, j-1);
    int c = f(s, i+1,j-1);
    int min = a<b?a:b;
    min = min<c?min:c;
    res[i][j] = min + 1;
    return res[i][j];
}

int main(int argc, const char *argv[]) {
    memset(res, -1, sizeof(res));
    string s;
    cin >> s;
    printf("%d", f(s.c_str(), 0, s.size()-1 ));
    return 0;
}