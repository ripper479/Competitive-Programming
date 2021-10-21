const ll N = 1e6;
ll fact[N],invfact[N];
ll calc(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res%mod * a%mod)%mod;
        a = (a%mod * a%mod)%mod;
        b >>= 1;
    }
    return res;
}
void pre(){
    fact[0]=1;
    repe(i,1,N-1){
        fact[i]=(i*fact[i-1])%mod;
    }
    invfact[N-1]=calc(fact[N-1],mod-2);
    for(ll i=N-2;i>=0;i--){
        invfact[i]=((i+1)*invfact[i+1])%mod;
    }
}
ll nCr(ll n,ll r){
    if(r>n or r<0 or n<0)   return 0;
    ll ans=(fact[n]*invfact[r])%mod;
    return (ans*invfact[n-r])%mod;
}
