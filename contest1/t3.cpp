#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;
  
int main() {  
    int n, k;
    cin >> n;
    while (n--) {
        cin >> k;
        for (int i = 0; i < k - 1; ++i) {
            int u, v;
            cin >> u >> v;
        }
        int ra = rand();
        switch(ra % 4) {
            case 0: cout << "00"; break;
            case 1: cout << "01"; break;
            case 2: cout << "10"; break;
            case 3: cout << "11"; break;
        }
    }
    return 0;  
}