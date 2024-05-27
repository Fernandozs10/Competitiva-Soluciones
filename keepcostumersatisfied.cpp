#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cassert>
using namespace std;

#define eps 1e-6
#define MAXN 1048576


pair<int, int> D[MAXN];

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

int main() {
    int testcase, N, x, y;
    cin >> testcase;
    while (testcase--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> x >> y;
            D[i] = make_pair(x, y);
        }
        sort(D, D + N, cmp);
        
        priority_queue<int> pQ; 
        int t = 0;
        for (int i = 0; i < N; i++) {
            pQ.push(D[i].first);
            t += D[i].first;
            if (t > D[i].second) {
                t -= pQ.top();
                pQ.pop();
            }
        }
        cout << pQ.size() << endl;
        if (testcase) {
            cout << endl;
        }
    }
    return 0;
}
