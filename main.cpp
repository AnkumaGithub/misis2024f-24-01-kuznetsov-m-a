#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

const int MOD = 998244353;
const int MAXA = 1e6+5;
vector<int> least_prime(MAXA);
void build_sieve() {
    for (int i = 2; i < MAXA; ++i) {
        if (least_prime[i] == 0) {
            for (int j = i; j < MAXA; j += i) {
                if (least_prime[j] == 0)
                    least_prime[j] = i;
            }
        }
    }
}

vector<int> get_primes(int x) {
    vector<int> primes;
    while (x > 1) {
        int p = least_prime[x];
        primes.push_back(p);
        while (x % p == 0)
            x /= p;
    }
    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    build_sieve();
    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<vector<int>> primes(n+1);
    for (int i = 1; i <= n; ++i) {

        cin >> a[i];
        primes[i] = get_primes(a[i]);
    }
    map<int, vector<int>> positions;
    for (int i = 1; i <= n; ++i) {
        for (int p : primes[i]) {
            positions[p].push_back(i);
        }
    }
    vector<int> dp(n+2, 0);
    dp[n] = 1;
    map<int, int> pointers;
    for (auto& kv : positions) {
        int p = kv.first;
        pointers[p] = kv.second.size() - 1;
    }
    for (int i = n; i >= 1; --i) {
        dp[i] = (i == n) ? 1 : 0;
        for (int p : primes[i]) {
            vector<int>& pos_list = positions[p];
            int& ptr = pointers[p];
            while (ptr >= 0 && pos_list[ptr] > i)
                --ptr;
            if (ptr + 1 < pos_list.size()) {
                int next_j = pos_list[ptr + 1];
                dp[i] = (dp[i] + dp[next_j]) % MOD;
            }
        }
    }
    cout << dp[1] % MOD << endl;
    return 0;
}