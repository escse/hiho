#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int x[] = {1,2,3};
    // istream_iterator<int> iend;
    vector<int> v(istream_iterator<int>(cin), (istream_iterator<int>()));
    for (auto i: v) cout << i << " ";
}