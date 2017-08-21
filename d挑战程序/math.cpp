bool is_prime(int n) {
    if (n <= 2) return false; //?
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return true;
    }
    return false;
}

//约数枚举
vector<int> divisor(int n) {
    vector<int> res;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) res.push_back(n/i);
        }
    }
    return res;
}

//分解
map<int, int> prime_factor(int n) {
    map<int, int> res;
    for (int i = 2; i * i <= n ; ++i) {
        while (n % i == 0) {
            ++res[i];
            n /= i;
        }
    }
    if (n != 1) res[n] = 1;
    return res;
}

//aishi filter
int prime[MAX_N];
bool is_prime[MAX_N+1];
//nloglogn
int sieve(int n) {
    int p = 0;
    for (int i = 0; i < n; ++i) {
        is_prime[i] = true;
    }
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            prime[p++] = i;
            for (int j = 2 * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return p;
}

//快速米
//n化成binary
long mod_pow(long x, long n, long m) {
    long res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % m;
        x = x * x % m;
        n >>= 1;
    }
    return res;
}

long mod_pow1(long x, long n, long m) {
    if (n == 0) return 1;
    long res = mod_pow1(x * x % m, n >> 1, mod);
    if (res & 1) res = res * x % m;
    return res;
}