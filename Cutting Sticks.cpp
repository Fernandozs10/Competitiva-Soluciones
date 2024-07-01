#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring> // Para memset

using namespace std;

int memo[52][52];
vector<int> v;

int f(int a, int b)
{
    if(b-a==1) return 0;
    
    if(memo[a][b]!=-1) return memo[a][b];
    
    int x = 4000000;
    
    for(int i = a+1; i < b; i++)
        x = min(v[b] - v[a] + f(a, i) + f(i, b), x);
        
    memo[a][b] = x;
    return x;
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    int L;
    int n;
    int aux;
    
    while(true)
    {
        cin >> L;
        if(L == 0) break;
        
        cin >> n;
        
        v.clear();
        v.push_back(0);
        for(int i = 0; i < n; i++)
        {
            cin >> aux;
            v.push_back(aux);
        }
        v.push_back(L);
        
        memset(memo, -1, sizeof(memo));
        
        cout << "The minimum cutting is " << f(0, n + 1) << "." << endl;
    }

    return 0;
}
