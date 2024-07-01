#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> primes;
int dp[1122][15]; 

void sieve() {
    bool is_prime[1125];
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= 1120; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= 1120; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= 1120; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

void countWays() {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1; 

    for (int p : primes) {
        for (int sum = 1120; sum >= p; --sum) {
            for (int k = 1; k <= 14; ++k) {
                dp[sum][k] += dp[sum - p][k - 1];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    countWays();

    int sum, n;
    while (cin >> sum >> n) {
        if (sum == 0 && n == 0) break;
        cout << dp[sum][n] << "\n";
    }

    return 0;
}
