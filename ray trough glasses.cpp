#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> f(1001, vector<int>(301, 0));

int main() {
    int i, j;
    f[0][0] = 1;
    f[1][0] = 2;
    for (i = 2; i <= 1000; i++) {
        for (j = 0; j < 300; j++) {
            f[i][j] = f[i-1][j] + f[i-2][j];
        }
        for (j = 0; j < 300; j++) {
            f[i][j+1] += f[i][j] / 10;
            f[i][j] %= 10;
        }
    }

    while (cin >> i) {
        j = 299;
        while (f[i][j] == 0) j--;
        while (j >= 0)
            cout << f[i][j--];
        cout << endl;
    }

    return 0;
}
