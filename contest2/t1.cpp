#include <iostream>
using namespace std;
int n, k;

int c2i(char c) {
    return c - 48;
}


void next(string& s) {
    for (int i = n; i >= 0 ; --i) {
        if (c2i(s[i]) <= k - 1 && (c2i(s[i]) + 1) * c2i(s[i-1]) <= k) {
            s[i] += 1;
            s.replace(i+1, n-i, string(n-i, '0'));
            break;
        }
    }
}

int main(int argc, const char *argv[]) {
    cin >> n >> k;
    string s(n + 2, '0');
    s[1] = '1';
    cout << s.substr(1,n) << endl;
    while (1) {
        next(s);
        if (s[0] == '1') break;
        cout << s.substr(1, n) << endl;
    }    
    return 0;
}