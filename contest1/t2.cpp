#include <iostream>
#include <cmath>
using namespace std;
  
int main() {  
    int n, k;
    cin >> n;
    while (n--) {
        cin >> k;
        k *= 2;
        for (int i = round(sqrt(k)); i >= 1; --i) {
            if (k % i != 0) continue;
            if ((k / i - i) % 2 == 1) {
                cout << i << endl;
                break;
            } 
        }
        
    }
    return 0;  
}