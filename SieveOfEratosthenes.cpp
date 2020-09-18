#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007

void SieveOfEratosthenes(ll n)      //Time Complexity: O(N*logNlogN)
{ 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (ll p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        {   
            for (ll i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    }  
    for (ll p=2; p<=n; p++) 
       if (prime[p]) 
          cout << p << " "; 
}
int main() 
{
  ll n;
  cin>>n;
  SieveOfEratosthenes(n);  
  return 0;
}