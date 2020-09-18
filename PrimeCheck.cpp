#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007

bool isPrime(ll n)          // Time Complexity: O(sqrt(N))
{
  if(n==1)  return 0;
  if(n==2)  return 1;
  if(n%2==0)  return 0;
  for(ll i=3;i*i<=n;i+=2)
  {
    if(n%i==0)  return 0;
  }
  return 1;
}
int main() 
{
  ll n;
  cin>>n;
  cout<<isPrime(n)<<endl;  
  return 0;
}
