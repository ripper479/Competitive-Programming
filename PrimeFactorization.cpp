#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007

void primeFactors(ll n)  
{   
    while (n % 2 == 0)  
    {  
        cout << 2 << " ";  
        n = n/2;  
    }  
    for (ll i = 3; i*i<=n; i = i + 2)  
    {  
        while (n % i == 0)  
        {  
            cout << i << " ";  
            n = n/i;  
        }  
    }  
    if (n > 2)  
        cout << n << " ";  
}
int main() 
{
  ll n;
  cin>>n;
  primeFactors(n);  
  return 0;
}