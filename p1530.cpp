/*
根据欧拉定理 b^{-1} = b{\phi(p)-1}
*/

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    long a, b, p;
    long res = 1;
    cin >> a >> b >> p;
    while(1) {
        res *= b;
        res %= p;
        if ((b *  res % p) == 1) {
            cout << (a * res) % p;
            return 0;
        }
    }
    return 0;
}
