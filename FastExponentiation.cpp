#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007

ll fastExponentiation(ll x,ll n)    //Time Complexity: O(logn)
{
  ll res=1;
  while(n)
  {
    if(n&1)
    {
      res=(res*x)%mod;
    }
    x=(x*x)%mod;
    n=n/2;
  }
  return res;
}
int main() 
{
  ll x,n;
  cin>>x>>n;
  cout<<fastExponentiation(x,n);  
  return 0;
}