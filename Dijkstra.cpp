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
typedef long long ll;        typedef long double ld;
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
 
ll n,m;
vector<pair<ll,ll>> g[100100];
void solve(){
    cin>>n>>m;
    rep(i,m){
        ll a,b,c;
        cin>>a>>b>>c;
        g[a].EB(MP(b,c));
    }
    priority_queue<pair<ll,ll>> pq;
    vector<ll> dis(n+1,mod*mod);
    vector<ll> vis(n+1,0);
    dis[1]=0;
    pq.push(MP(0,1));
    while(!pq.empty()){
        ll node=pq.top().S;
        pq.pop();
        if(vis[node])   continue;
        vis[node]=1;
        for(auto neigh:g[node]){
            if(dis[node]+neigh.S<dis[neigh.F]){
                dis[neigh.F]=dis[node]+neigh.S;
                pq.push(MP(-dis[neigh.F],neigh.F));
            }
        }
    }
    repe(i,1,n){
        cout<<dis[i]<<" ";
    }
    cout<<endl;
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
