#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool isPermutation(int a, int b) {
    vector<int> countA(10, 0), countB(10, 0);
    
    while (a > 0) {
        countA[a % 10]++;
        a /= 10;
    }
   
    while (b > 0) {
        countB[b % 10]++;
        b /= 10;
    }

 
    return countA == countB;
}

int main() {
    int n;
    bool firstCase = true;

    while (cin >> n && n != 0) {
        if (!firstCase) {
            cout << endl;
        }
        firstCase = false;
        
        bool found = false;

        for (int N2 = 1234; N2 <= 98765 / n; ++N2) {
            int N1 = N2 * n;

            if (isPermutation(N1, N2)) {
                found = true;
                printf("%05d / %05d = %d\n", N1, N2, n);
            }
        }

        if (!found) {
            cout << "There are no solutions for " << n << "." << endl;
        }
    }

    return 0;
}
