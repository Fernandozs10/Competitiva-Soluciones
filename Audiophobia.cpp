#include <iostream>
#include <algorithm>
#define oo 0xffffff
#define min(x, y) ((x)<(y)?(x):(y))
#define max(x, y) ((x)>(y)?(x):(y))

using namespace std;

int main() {
    int n, m, q, cases = 0;
    while (cin >> n >> m >> q) {
        if (n == 0) break;
        int f[101][101], i, j, k, x, y, b;
        for (i = 1; i <= n; f[i][i] = 0, i++)
            for (j = 1; j <= n; j++)
                f[i][j] = oo;
        while (m--) {
            cin >> x >> y >> b;
            f[x][y] = min(f[x][y], b);
            f[y][x] = f[x][y];
        }
        for (k = 1; k <= n; k++)
            for (i = 1; i <= n; i++)
                for (j = 1; j <= n; j++)
                    f[i][j] = min(f[i][j], max(f[i][k], f[k][j]));
        if (cases)
            cout << "\n";
        cout << "Case #" << ++cases << "\n";
        while (q--) {
            cin >> x >> y;
            if (f[x][y] != oo)
                cout << f[x][y] << "\n";
            else
                cout << "no path\n";
        }
    }
    return 0;
}
