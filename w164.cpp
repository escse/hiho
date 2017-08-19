#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, const char *argv[]) {
    int n;
    string s;
    cin >> n;
    cin.get();
    int a,b,c,d;
    int minVal = s.size() + 1;
    while (n--) {
        getline(cin, s);
        a = b = 0;
        c = count(s.begin(), s.end(), '0');
        d = s.size() - a;
        minVal = b + c;
        cout << a << ":" << b << ":" << c << ":"<< d << endl;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '0') {
                a += 1;
                c -= 1;
            } else {
                b += 1;
                d -= 1;
            }
            cout << a << ":" << b << ":" << c << ":"<< d << endl;
            minVal = min(minVal, b + c);
        }
        cout << minVal << endl;
        s.clear();
    }
    return 0;
}