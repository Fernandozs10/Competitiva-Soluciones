#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

int main() {
    int testcase, cases = 0;
    int n, m;
    long long x;

    cin >> testcase;
    while (testcase--) {
        cin >> n >> m;
        vector<long long> A(n);
        
        for (int i = 0; i < n; i++) {
            cin >> A[i];
            A[i] = -A[i];  
        }
        
        for (int i = 0; i < n; i++) {
            cin >> x;
            A[i] += x;  
        }
        
        sort(A.begin(), A.end(), greater<long long>());  
        
        long long p = 0;
        for (int i = 0, j = n - 1; i < m; i++, j--) {
            if (A[j] < 0) {
                n--;  
            }
        }
        
        for (int i = 0; i < n; i++) {
            p += A[i];  
        }
        
        cout << "Case " << ++cases << ": ";
        if (p <= 0) {
            cout << "No Profit" << endl;
        } else {
            cout << p << endl;
        }
    }
    
    return 0;
}
