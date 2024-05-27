#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;

int main() 
{
  vector<long long> numeros;

  for(int i=0;i<32;i++)
  {
    for(int j=0;j<32;j++)
    {
      long long p=static_cast<long long> (pow(2,i)*pow(3,j));
      if(p<=1LL<<50)
      {
        numeros.push_back(p);
      }
    }
  }
  sort(numeros.begin(),numeros.end());
  
  long long n;
  
  while(cin>>n&&n!=0)
  {
    auto it=lower_bound(numeros.begin(),numeros.end(),n);
    cout<<*it<<endl;
  }
  return 0;
}

