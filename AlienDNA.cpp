#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;

void solve(){
  int n;
  cin >> n;
  vector<string> a(n);
  for (int i = 0;i < n; i++) cin >> a[i];
  int ans = 0, bits = (1<<30) - 1;
  for (string& s:a){
    int cur = 0;
    for(char ch : s){
      cur |= 1 << (ch - 'a');
    }
    if (cur & bits){
      bits &= cur;
    } else {
      ans++;
      bits = cur;
    }
  }
  cout << ans << "\n";
}
int main(){
  ios:: sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--){
    solve();
  }
}
