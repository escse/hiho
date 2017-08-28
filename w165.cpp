#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

map<char, int> dic;

bool valid(int n) {
    for (auto& p: dic) {
        if (p.second > (1+n) / 2)
            return false;   
    }
    return true;
}

int main(int argc, const char *argv[]) {
    string s;
    string out;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        ++dic[s[i]];
    }
    char f = -1;
    if (!valid(n)) cout << "INVALID";
    for (int i = 0; i < s.size() ; ++i) {
        for (auto& p: dic) {
            if (p.first == f || p.second ==0 ) continue;
            --p.second;
            if (valid(n-1)) {
                out += p.first;
                f = p.first;
                --n;
                break;
            }
            else ++p.second;
        }
    }
    cout << out;
    return 0;
}