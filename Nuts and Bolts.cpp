#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int g[1005][1005], gt[1005];
int mx[1005], my[1005], used[1005];

int dfs(int now) {
    int i, x;
    for (i = 0; i < gt[now]; i++) {
        x = g[now][i];
        if (!used[x]) {
            used[x] = 1;
            if (my[x] == 0 || dfs(my[x])) {
                mx[now] = x, my[x] = now;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int n, m, i, j, x;
    int t, cases = 0;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        fill(begin(gt), end(gt), 0);
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                cin >> x;
                if (x)
                    g[i][gt[i]++] = j + n;
            }
        }
        fill(begin(mx), end(mx), 0);
        fill(begin(my), end(my), 0);
        int ans = 0;
        for (i = 1; i <= n; i++) {
            if (!mx[i]) {
                fill(begin(used), end(used), 0);
                if (dfs(i))
                    ans++;
            }
        }
        cout << "Case " << ++cases << ": a maximum of " << ans << " nuts and bolts can be fitted together\n";
    }
    return 0;
}
