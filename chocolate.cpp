#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int tc;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T=1;
    cin >> T;
    while(T--){
        int l,r,s;
        cin >> l >> r >> s;
        vector<int> cl(N),cr(N),cs(N);
        for(int i=0; i<l ;i++){
            int x;
            cin >> x;
            cl[x]++;
        }
        for(int i=0; i<r ;i++){
            int x;
            cin >> x;
            cr[x]++;
        }
        for(int i=0; i<s ;i++){
            int x;
            cin >> x;
            cs[x]++;
        }
        cout<< "Case #" << ++tc << ":\n";
        int hl=0,nhl=0,hr=0,nhr=0,hs=0,nhs=0;
        for(int i=0;i<N;i++){
            if(cl[i] && !cr[i] && !cs[i]){
                hl++;
            }
            if(!cl[i] && cr[i] && cs[i]){
                nhl++;
            }
            if(cr[i] && !cl[i] && !cs[i]){
                hr++;
            }
            if(!cr[i] && cl[i] && cs[i]){
                nhr++;
            }
            if(cs[i] && !cl[i] && !cr[i]){
                hs++;
            }
            if(!cs[i] && cl[i] && cr[i]){
                nhs++;
            }
        }
        cout<< hl << ' ' << nhl <<'\n';
        cout<< hr << ' ' << nhr <<'\n';
        cout<< hs << ' ' << nhs <<'\n';
    }
    return 0;
}
