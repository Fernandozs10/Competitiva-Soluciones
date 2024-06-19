#include <bits/stdc++.h>
#define pb push_back
#define INF (1<<30)
#define all(x) x.begin(), x.end()
#define ms(a, v) fill(a, a + sizeof(a) / sizeof(a[0]), v)
#define II ({int a; cin >> a; a;})
#define LL  ({ll  a; cin >> a; a;})
#define EPS 1e-10
#define pi acos(0.0)
using namespace std;
typedef long long ll;
#define rep(i, n) for(auto i = 0; i < n; i++)
#define For(i, n) for(auto i = 1; i <= n; i++)
#define forstl(i, n) for(auto i = n.begin(); i != n.end(); i++)
#define forab(i, a, b) for(auto i = a; i <= (b); i++)
#define forba(i, b, a) for(auto i = b; i >= (a); i--)

#define sz 505

int Cnt[sz][30];
int gC[sz][30];
char St[sz];
int n, m;

vector<int> edges[sz + sz];
int LeftMatch[sz + sz], RightMatch[sz + sz];
int N;
bool visited[sz + sz];

void clear() {
    rep(i, sz + sz) edges[i].clear(), LeftMatch[i] = RightMatch[i] = -1;
}

bool match(int u) {
    rep(i, edges[u].size()) {
        int v = edges[u][i];

        if (visited[v]) continue;

        visited[v] = true;

        if (RightMatch[v] == -1 || match(RightMatch[v]) == true) {
            RightMatch[v] = u;
            LeftMatch[u] = v;
            return true;
        }
    }
    return false;
}

int bipartiteMatch() {
    int matching = 0;
    while (true) {
        fill(begin(visited), end(visited), false);
        bool foundMatch = false;
        rep(i, N) {
            if (LeftMatch[i] != -1) continue;
            if (match(i)) foundMatch = true, matching++;
        }
        if (!foundMatch) break;
    }
    return matching;
}

bool ChecK(int dPos, int qPos) {
    rep(i, 26) {
        if (Cnt[dPos][i] < gC[qPos][i]) return false;
    }
    return true;
}

void __makeGraph() {
    rep(i, n) {
        rep(j, m) {
            if (ChecK(i, j)) edges[j].pb(m + i);
        }
    }
    N = m;
}

int main() {
    while (cin >> n >> m) {
        ms(Cnt, 0);
        rep(i, n) {
            cin >> St;
            int tot = strlen(St);
            rep(j, tot) Cnt[i][St[j] - 'a']++;
        }
        ms(gC, 0);
        rep(i, m) {
            cin >> St;
            int tot = strlen(St);
            rep(j, tot) gC[i][St[j] - 'a']++;
        }
        clear();
        __makeGraph();
        int ans = bipartiteMatch();
        cout << ans << "\n";
    }
}
