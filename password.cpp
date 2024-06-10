#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
using namespace std;

const int MAX_CHARS = 6;
const int MAX_ROWS = 5;

vector<char> getChars(int rows, int cols) {
  vector<char> chars;
  string line;

  for (int i = 0; i < rows; ++i) {
    getline(cin, line);
    // Remove trailing newline character if present
    line.erase(remove(line.begin(), line.end(), '\n'), line.end());
    for (int j = 0; j < cols && j < line.size(); ++j) {
      chars.push_back(line[j]);
    }
  }
  return chars;
}

int main() {
  int tc, q;

  cin >> tc;

  while (tc--) {
    cin >> q;

    vector<char> a = getChars(MAX_ROWS, MAX_CHARS);
    vector<char> b = getChars(MAX_ROWS, MAX_CHARS);

    for (int i = 0; i < MAX_ROWS; ++i) {
      sort(a.begin() + i * MAX_CHARS, a.begin() + (i + 1) * MAX_CHARS);
      sort(b.begin() + i * MAX_CHARS, b.begin() + (i + 1) * MAX_CHARS);
    }

    char p1, p2, p3, p4, p5;
    int count = 0;

    for (int i = 0; i < MAX_CHARS && count < q; ++i) {
      if (i > 0 && a[i] == a[i - 1]) {
        continue;
      }
      for (int j = 0; j < MAX_CHARS && count < q; ++j) {
        if (j > 0 && a[MAX_CHARS * 0 + j] == a[MAX_CHARS * 0 + j - 1]) {
          continue;
        }
        for (int k = 0; k < MAX_CHARS && count < q; ++k) {
          if (k > 0 && a[MAX_CHARS * 1 + k] == a[MAX_CHARS * 1 + k - 1]) {
            continue;
          }
          for (int l = 0; l < MAX_CHARS && count < q; ++l) {
            if (l > 0 && a[MAX_CHARS * 2 + l] == a[MAX_CHARS * 2 + l - 1]) {
              continue;
            }
            for (int m = 0; m < MAX_CHARS && count < q; ++m) {
              if (m > 0 && a[MAX_CHARS * 3 + m] == a[MAX_CHARS * 3 + m - 1]) {
                continue;
              }

              p1 = a[i];
              p2 = a[MAX_CHARS * 0 + j];
              p3 = a[MAX_CHARS * 1 + k];
              p4 = a[MAX_CHARS * 2 + l];
              p5 = a[MAX_CHARS * 3 + m];

              if (binary_search(b.begin(), b.end(), p1) &&
                  binary_search(b.begin(), b.end(), p2) &&
                  binary_search(b.begin(), b.end(), p3) &&
                  binary_search(b.begin(), b.end(), p4) &&
                  binary_search(b.begin(), b.end(), p5)) {
                count++;
              }
            }
          }
        }
      }
    }

    if (count == q) {
      cout << p1 << p2 << p3 << p4 << p5 << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
