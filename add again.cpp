#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, i;
    vector<unsigned long long> f(20, 1);
    for (i = 1; i < 20; i++)
        f[i] = f[i-1] * i;
    
    while (cin >> n && n) {
        vector<int> dec(10, 0);
        int x, sum = 0;
        for (i = 0; i < n; i++) {
            cin >> x;
            dec[x]++;
            sum += x;
        }

        unsigned long long C = f[n], tmp = 0, d10 = 1;
        for (i = 0; i < 10; i++)
            C /= f[dec[i]];

        for (i = 0; i < n; i++) {
            tmp += d10;
            d10 = d10 * 10;
        }

        C = C * sum / n * tmp;
        cout << C << endl;
    }
    return 0;
}
