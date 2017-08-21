#include <iostream>
#include <limits>
int main() {
    auto max = std::numeric_limits<int>::max();
    auto inf = std::numeric_limits<int>::infinity();
 
    // if(inf > max)
        std::cout << inf << " is greater than " << max << '\n';
}