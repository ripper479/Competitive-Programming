#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007

void segmentedSieve(ll L,ll R) {        //Time Complexity: O((R-L+1)loglogR + sqrt(R)loglog(sqrt(R)))
    ll lim = sqrt(R);
    vector<bool> mark(lim + 1, false);
    vector<ll> primes;
    for (ll i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (ll j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<bool> isPrime(R - L + 1, true);
    for (ll i : primes)
        for (ll j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    for(ll i=0;i<=(R-L);i++)
    {
      if(isPrime[i])
      {
        cout<<L+i<<" ";
      }
    }
    cout<<endl;
}
int main() 
{
  ll a,b;
  cin>>a>>b;
  segmentedSieve(a,b);  
  return 0;
}