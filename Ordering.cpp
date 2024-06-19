#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;

string s;
int g[26][26], n, has;
char ans[26], used[26] = {};

void dfs(int Idx) {
    if (Idx == n) {
        has = 1;
        cout << ans[0];
        for (int i = 1; i < n; i++)
            cout << " " << ans[i];
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            int j;
            for (j = 0; j < Idx; j++) {
                if (g[s[i] - 'A'][ans[j] - 'A'])
                    break;
            }
            if (j == Idx) {
                ans[Idx] = s[i];
                used[i] = 1;
                dfs(Idx + 1);
                used[i] = 0;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Para ignorar el salto de línea después del número de casos
    string line;
    while (t--) {
        cin.ignore(); // Para ignorar la línea vacía entre los casos
        getline(cin, line);
        stringstream sin(line);
        s = "";
        while (sin >> line)  s += line;
        sort(s.begin(), s.end());
        getline(cin, line);
        memset(g, 0, sizeof(g));
        sin.clear();
        sin.str(line);
        while (sin >> line) {
            g[line[0] - 'A'][line[2] - 'A'] = 1;
        }
        n = s.length();
        has = 0;
        dfs(0);
        if (!has)
            cout << "NO\n";
        if (t)
            cout << "\n";
    }
    return 0;
}
