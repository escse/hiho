#include <iostream>
using namespace std;

int main() {
    int n, m;
    int a, b, c, d;
    int x, y, z;
    cin >> n >> m;
    cin >> a >> b >> c >> d;
    cin >> x >> y >> z;
    int maxVal = 0;
    int i, j, k;
    int tn, tm;
    // case 1
    tn = n; tm = m;
    i = min(tn/a, tm/b); tn -= i *  a; tm -= i * b; 
    j = tn / d; tn -= j * d;
    k = tm / c; tm -= k * c;
    maxVal = max(maxVal, i * x + j * z + k * y);
    // case 2.1 白色
    tn = n; tm = m;
    j = tn / d; tn -= j * d;
    i = min(tn/a, tm/b); tn -= i *  a; tm -= i * b; 
    k = tm / c; tm -= k * c;
    maxVal = max(maxVal, i * x + j * z + k * y);
    // case 2.2
    tn = n; tm = m;
    j = tn / d; tn -= j * d;
    k = tm / c; tm -= k * c;
    i = min(tn/a, tm/b); tn -= i *  a; tm -= i * b; 
    maxVal = max(maxVal, i * x + j * z + k * y);
    // case 3.1
    tn = n; tm = m;
    k = tm / c; tm -= k * c;
    i = min(tn/a, tm/b); tn -= i *  a; tm -= i * b; 
    j = tn / d; tn -= j * d;
    maxVal = max(maxVal, i * x + j * z + k * y);
    // case 3.2
    tn = n; tm = m;
    k = tm / c; tm -= k * c;
    j = tn / d; tn -= j * d;
    i = min(tn/a, tm/b); tn -= i *  a; tm -= i * b; 
    maxVal = max(maxVal, i * x + j * z + k * y);
    cout <<  maxVal <<  endl;
}