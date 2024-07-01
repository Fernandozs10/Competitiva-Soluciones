#include <iostream>
#include <vector>
using namespace std;

int main() 
{
  vector<long long> hojas={0,1};

  for (int i=2;i<=85;++i) 
  {
    hojas.push_back(hojas[i-1]+hojas[i-2]);
  }

  int nivel;

  while (cin>>nivel&&nivel!=0) 
  {
    cout<<hojas[nivel]<<endl;
  }

  return 0;
}
