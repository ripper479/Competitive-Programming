struct RMQ{
    ll n,k;
    vector<vector<ll>> st;
    vector<ll> log;
    void build(vector<ll> &arr){
        n=sz(arr);
        log.resize(n+1);
        log[1]=0;
        repe(i,2,n){
            log[i]=1+log[i/2];
        }
        k=log[n];
        st.resize(n+1);
        rep(i,n+1)  st[i].resize(k+1);
        rep(i,n)    st[i][0]=arr[i];
        repe(j,1,k){
            for(ll i=0;i+(1<<j)<=n;i++){
                st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
            }
        }
    }
    ll query(ll l,ll r){
        ll j=log[r-l+1];
        return min(st[l][j],st[r-(1<<j)+1][j]);
    }
};
