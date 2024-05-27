#include <iostream>
using namespace std;

long long countBits(long long n) 
{
  if (n == 0) 
  {
    return 0;
  } 
  else 
  {
    return n % 2 + countBits(n / 2);
  }
}

int main()
{
  long long numCasos;
  cin >> numCasos;

  for (int i = 0; i < numCasos; i++)
  {
    long long N;
    cin >> N;
    cout << countBits(N)<<endl;
  }
  return 0;
}
