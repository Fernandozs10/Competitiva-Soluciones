#include <iostream>
#include <cmath>
using namespace std;

int arr_d[100001], arr_h[100001];

int main() {
    long long test, a, b, k, i, j, d, h;
    arr_d[1] = 1;
    arr_h[1] = 1;
    
    for (i = 2; i <= 100000; i++) {
        d = h = 0;
        for (j = 1; (j * j) <= i; j++) {
            if (i % j == 0) {
                if (j == i / j) {
                    d += 1;
                    h += j;
                } else {
                    d += 2;
                    h += j;
                    h += i / j;
                }
            }
        }
        arr_d[i] = d;
        arr_h[i] = h;
    }

    cin >> test;
    while (test--) {
        cin >> a >> b >> k;
        d = h = 0;
        if (a % k != 0) {
            i = a % k;
            a = a + k - i;
        }
        for (i = a; i <= b; i += k) {
            d += arr_d[i];
            h += arr_h[i];
        }
        cout << d << " " << h << "\n";
    }
    return 0;
}
