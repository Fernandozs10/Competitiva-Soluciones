#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n, i;
pair<double, double> island[1005];

int solve() {
    double r = -1e9;
    int cnt = 0;

    sort(island, island + n);
    i = 0;
    while (i < n) {
        while (i < n && island[i].first <= r) {
            r = min(r, island[i].second);
            ++i;
        }
        ++cnt;
        if (i < n)
            r = island[i].second;
    }

    return cnt - 1;
}

int main() {
    double x, y, d;
    int flag, cas = 0;

    while (cin >> n >> d && n) {
        flag = 0;
        for (i = 0; i < n; ++i) {
            cin >> x >> y;

            if (y > d) flag = 1;
            else {
                double dist = sqrt(d * d - y * y);
                island[i].first = x - dist;
                island[i].second = x + dist;
            }
        }
        cout << "Case " << ++cas << ": " << (flag ? -1 : solve()) << endl;
    }

    return 0;
}
