#include <iostream>
using namespace std;

char pa[500][500][60] = {};

int main() {
    int t;
    pa[0][0][0] = 1;

    // Precálculo de combinaciones
    for (int i = 1; i < 500; i++) {
        pa[i][0][0] = 1;
        for (int j = 1; j <= i; j++) {
            for (int k = 0; k < 60; k++) {
                pa[i][j][k] += pa[i - 1][j - 1][k] + pa[i - 1][j][k];
            }
            for (int k = 0; k < 59; k++) {
                if (pa[i][j][k] >= 10) {
                    pa[i][j][k + 1] += pa[i][j][k] / 10;
                    pa[i][j][k] %= 10;
                }
            }
        }
    }

    cin >> t;
    while (t--) {
        int n, m, x, y, i;
        cin >> n >> m;
        x = n;
        for (i = 0; i < m; i++) {
            cin >> y;
            x -= y;
        }
        x -= m - 1;

        if (x + m < m || m < 0) {
            cout << "0" << endl;
            continue;
        }

        int k = 59;
        while (k >= 0 && pa[x + m][m][k] == 0) {
            k--;
        }

        if (k < 0) {
            cout << "0" << endl;
            continue;
        }

        while (k >= 0) {
            cout << static_cast<int>(pa[x + m][m][k]);
            k--;
        }

        cout << endl;
    }

    return 0;
}
