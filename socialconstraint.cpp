#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Constraint {
    int a, b, c;
};

int main() {
    int n, m;
    while (cin >> n >> m, n || m) {
        vector<int> people(n);
        vector<Constraint> constraints(m);

        for (int i = 0; i < n; ++i) {
            people[i] = i;
        }

        for (int i = 0; i < m; ++i) {
            cin >> constraints[i].a >> constraints[i].b >> constraints[i].c;
        }

        int validPermutations = 0;

        do {
            bool valid = true;
            for (const auto& con : constraints) {
                int posA = find(people.begin(), people.end(), con.a) - people.begin();
                int posB = find(people.begin(), people.end(), con.b) - people.begin();
                int distance = abs(posA - posB);
                
                if ((con.c > 0 && distance > con.c) || (con.c < 0 && distance < -con.c)) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                ++validPermutations;
            }
        } while (next_permutation(people.begin(), people.end()));

        cout << validPermutations << endl;
    }

    return 0;
}
