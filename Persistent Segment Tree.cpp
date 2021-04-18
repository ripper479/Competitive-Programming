#include<bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
using namespace std;
#define F first
#define S second
#define EB emplace_back
#define MP make_pair
#define all(o) (o).begin(), (o).end()
#define mset(m,v) memset(m,v,sizeof(m))
#define rep(i,n) for(ll i=0;i<(n);++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define revlp(i,a,b) for(ll i=a;i>=b;i--)
#define remin(a,b) (a=min((a),(b)))
#define remax(a,b) (a=max((a),(b))) 
#define sz(x) (ll)(x).size()
#define endl '\n'
typedef int ll;        typedef long double ld;
typedef pair<ll,ll> pi;     typedef vector<ll> vi;
typedef vector<pi> vpi;       typedef vector<vi> graph;
long long mod=1000000007;     long double EPS=1e-9;
#ifndef ONLINE_JUDGE
#define debarr(a,n)cerr<<#a<<":";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<endl;
#define debmat(mat,row,col)cerr<<#mat<<":\n";for(int i=0;i<row;i++){for(int j=0;j<col;j++)cerr<<mat[i][j]<<" ";cerr<<endl;}
#define pr(...)dbs(#__VA_ARGS__,__VA_ARGS__)
template<class S,class T>ostream &operator<<(ostream &os,const pair<S,T> &p){return os<<"("<<p.first<<","<<p.second<<")";}
template<class T>ostream &operator<<(ostream &os,const vector<T> &p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class T>ostream &operator<<(ostream &os,const set<T>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class T>ostream &operator<<(ostream &os,const multiset<T>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class S,class T>ostream &operator<<(ostream &os,const map<S,T>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class T>void dbs(string str,T t){cerr<<str<<":"<<t<<"\n";}
template<class T,class...S>void dbs(string str,T t,S... s){int idx=str.find(',');cerr<<str.substr(0,idx)<<":"<<t<<",";dbs(str.substr(idx+1),s...);}
#else
#define pr(...){}
#define debarr(a,n){}
#define debmat(mat,row,col){}
#endif
 

/*  Count of distinct elements in [l,r]
*/
const ll N = 1e7;
ll n,q;
struct node{
    ll lc,rc,sum;
    node(){
        lc=rc=-1;
        sum=0;
    }
}t[N];
ll cnt;
ll root[30005];
void build(ll id,ll l,ll r){
    if(l==r){
        return;
    }
    t[id].lc=++cnt;
    t[id].rc=++cnt;
    ll mid=(l+r)/2;
    build(t[id].lc,l,mid);
    build(t[id].rc,mid+1,r);
}
ll update(ll id,ll l,ll r,ll pos,ll val){
    if(l==r){
        t[++cnt].sum=val+t[id].sum;
        return cnt;
    }
    ll mid=(l+r)/2;
    ll nid=++cnt;
    t[nid].lc=t[id].lc;
    t[nid].rc=t[id].rc;
    if(pos<=mid){
        t[nid].lc=update(t[id].lc,l,mid,pos,val);
    }
    else{
        t[nid].rc=update(t[id].rc,mid+1,r,pos,val);
    }
    t[nid].sum=t[t[nid].lc].sum+t[t[nid].rc].sum;
    return nid;
}
ll query(ll id,ll l,ll r,ll lq,ll rq){
    if(rq<l or lq>r)    return 0;
    if(lq<=l and r<=rq) return t[id].sum;
    ll mid=(l+r)/2;
    return query(t[id].lc,l,mid,lq,rq)+query(t[id].rc,mid+1,r,lq,rq);
}
void solve(){
    cin>>n;
    map<ll,ll> mp;
    build(cnt,0,n-1);
    repe(i,1,n){
        ll x;
        cin>>x;
        if(mp.find(x)!=mp.end()){
            root[i]=update(root[i-1],0,n-1,mp[x],-1);
            root[i]=update(root[i],0,n-1,i-1,1);
        }
        else{
            root[i]=update(root[i-1],0,n-1,i-1,1);
        }
        mp[x]=i-1;
    }
    cin>>q;
    while(q--){
        ll a,b;
        cin>>a>>b;
        cout<<query(root[b],0,n-1,a-1,b-1)<<endl;
    }
}
 
 
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //cout<<fixed<<setprecision(15);
    //clock_t begin = clock();
    ll tc=1;//cin>>tc;
    for(ll i=1;i<=tc;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    // clock_t end = clock();double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;cerr << elapsed_secs;
}