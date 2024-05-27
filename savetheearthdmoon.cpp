#include <cmath>
#include <iostream>
#include <math.h>
using namespace std;

int main () {
  double T,S,D;
  int cases;
  cin >> cases;

  for (int i = 0; i < cases; i++){
    cin >> T >> S >> D;
    T = T * 60 * 60 * 24;
    D = D * 1000 * 100 * 10;
    double ve = D/T;

    if (floor(ve) > 0){
      cout << "Remove " << (int)floor(ve) << " tons" << endl;
    }
    else {
      cout << "Add " << (int)floor(abs(ve))<<" tons" << endl;
    }
  }
  return 0;
}
