#include <iostream>
#include <vector>
#include <cstring>
#include <bitset>
using namespace std;

typedef vector<int> vi;

vector<vi> AdjList;
bitset<30> visited, appeared;
vi finishOrder;

void dfs(int u) {
    visited.set(u);

    for (int i = 0; i < (int) AdjList[u].size(); i++) {
        int v = AdjList[u][i];
        if (!visited[v]) {
            dfs(v);
        }
    }

    finishOrder.push_back(u);
}

int main() {
    string s, ps;
    AdjList.assign(30, vi());

    cin >> ps;
    while (cin >> s, s != "#") {
        for (int i = 0; i < (int) s.length() && i < (int) ps.length(); i++) {
            if (ps[i] != s[i]) {
                appeared.set(ps[i] - 'A');
                appeared.set(s[i] - 'A');
                AdjList[ps[i] - 'A'].push_back(s[i] - 'A');
                break;
            }
        }
        ps = s;
    }

    for (int i = 0; i < 26; i++) {
        if (!visited[i] && appeared[i])
            dfs(i);
    }

    for (int i = finishOrder.size() - 1; i >= 0; i--) {
        cout << char(finishOrder[i] + 'A');
    }
    cout << endl;

    return 0;
}
