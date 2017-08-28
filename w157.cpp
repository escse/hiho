#include <iostream>
#include <cstring>
using namespace std;
int digits[100];
int res[100];
int size;
int mult() {
    int c = 0;;
    for (int i = 0; i < size; ++i) {
        c += digits[size - i - 1] << 1;
        digits[size - i - 1] = c % 10;
        c /= 10;
    }
    return c;
}

int main(int argc, char const *argv[]) {
    int n;
    string s;
    cin >> n;
    cin.get();
    memset(digits, 0, sizeof(digits));
    memset(res, 0, sizeof(res));
    while(n--) {
        int i = 0;
        getline(cin, s);
        size = s.size() - 2;
        for (i = 0; i < size; ++i)
            digits[i] = s[i + 2] - 48;
        for (i = 0; i < size; ++i) {
            res[i] = mult();
        }
        for (i = 0; i < size; ++i) {
            if (digits[i]) break;
        }
        if (i != size) cout << "NO\n";
        else {
            int end;
            for (end = size - 1; i >= 0; --i) {
                if (res[end]) break;
            }
            cout << "0.";
            for (i = 0; i <= end; ++i) {
                cout << res[i];
            }
            cout << "\n";
        }
    }
    return 0;
}