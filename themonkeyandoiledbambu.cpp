#include <bits/stdc++.h>
using namespace std;

/*
2
5
1 6 7 11 13
4
3 9 10 14
*/

bool alcanzarCima(const vector<int>& arr,int k)
{
  int altura=0;
  
  for(int i=0;i<arr.size();i++)
  {
    if(arr[i]-altura>k)
    {
      return false;
    }
    else if(arr[i]-altura==k)
    {
      k--;
    }
    altura=arr[i];
  }
  return true;
}

int fuerzaMinima(const vector<int> &arr)
{
  int izquierda=1;
  int derecha=arr.back();

  while(izquierda<derecha)
  {
    int medio=izquierda+(derecha-izquierda)/2;
    if(alcanzarCima(arr,medio))
    {
      derecha=medio;
    }
    else
    {
      izquierda=medio+1;
    }
  }
  return izquierda;
}

int main()
{
  int t,c=0;
  cin>>t;
  
  while(t--)
  {
    c++;
    int n;
    cin>>n;
    vector<int> arr;
    
    for(int i=0;i<n;i++)
    {
      int x;
      cin>>x;
      arr.push_back(x);
    }
    
    int fuerza=fuerzaMinima(arr);
    cout<<"Case "<<c<<": "<<fuerza<<endl;
  }
  return 0;
}

