#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, w;
        cin >> n >> w;

        vector<int> pesos(n);
        for (int i = 0; i < n; ++i) {
            cin >> pesos[i];
        }
        sort(pesos.begin(), pesos.end());

        int count = 0;
        int ptotal = 0;

        for (int i = 0; i < n; ++i) {
            if (ptotal + pesos[i] <= w) {
                ptotal += pesos[i];
                count++;
            }
            else {
                break;
            }
        }

        cout << count << endl;
    }

    return 0;
}
