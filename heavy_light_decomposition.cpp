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
 
const ll N = 2e5+5;
vector<ll> g[N];
ll n,q;
ll arr[N];
struct node{
    ll maxi;
    node(){
        maxi=INT_MIN;
    }
};
struct hld{
    vector<ll> depth,sz,par,bigchild,label,chain,rlabel;
    ll label_time;
    vector<node> t;
    hld(){
        label_time=0;
        depth.resize(n+1);
        sz.resize(n+1);
        par.resize(n+1);
        bigchild.resize(n+1);
        label.resize(n+1);
        chain.resize(n+1);
        rlabel.resize(n+1);
        t.resize(4*(n+1));
        rep(i,n+1){
            bigchild[i]=-1;
            chain[i]=i;
        }
        dfs_size(1,0,0);dfs_label(1,0);dfs_chain(1,0);getRlabel();
        build(1,0,n-1);
    }
    node merge(node a,node b){
        node ans;
        ans.maxi=max(a.maxi,b.maxi);
        return ans;
    }
    void build(ll id,ll l,ll r){
        if(l==r){
            ll nn=rlabel[l];
            t[id].maxi=arr[nn-1];
            return;
        }
        ll mid=(l+r)/2;
        build(2*id,l,mid);
        build(2*id+1,mid+1,r);
        t[id]=merge(t[2*id],t[2*id+1]);
    }
    void update(ll id,ll l,ll r,ll pos,ll val){
        if(pos<l or pos>r)  return;
        if(l==r){
            t[id].maxi=val;
            return;
        }
        ll mid=(l+r)/2;
        update(2*id,l,mid,pos,val);
        update(2*id+1,mid+1,r,pos,val);
        t[id]=merge(t[2*id],t[2*id+1]);
    }
    node query(ll id,ll l,ll r,ll lq,ll rq){
        if(r<lq or l>rq)    return node();
        if(lq<=l and rq>=r) return t[id];
        ll mid=(l+r)/2;
        return merge(query(2*id,l,mid,lq,rq),query(2*id+1,mid+1,r,lq,rq));
    }
    void dfs_size(ll nn,ll pp,ll d){
        sz[nn]=1;
        depth[nn]=d;
        par[nn]=pp;
        ll bigc=-1,bigv=-1;
        for(auto x:g[nn]){
            if(x!=pp){
                dfs_size(x,nn,d+1);
                sz[nn] += sz[x];
                if (sz[x] > bigv) {
                    bigc = x;
                    bigv = sz[x];
                }
            }
        }
        bigchild[nn]=bigc;
    }
    void dfs_label(ll nn,ll pp){
        label[nn]=label_time++;
        if(bigchild[nn]!=-1)    dfs_label(bigchild[nn],nn);
        for(auto x:g[nn]){
            if(x!=pp and x!=bigchild[nn]){
                dfs_label(x,nn);
            }
        }
    }
    void dfs_chain(ll nn,ll pp){
        if(bigchild[nn]!=-1)    chain[bigchild[nn]]=chain[nn];
        for(auto x:g[nn]){
            if(x!=pp)    dfs_chain(x,nn);
        }
    }
    void getRlabel(){
        repe(i,1,n){
            rlabel[label[i]]=i;
        }
    }
    ll query_path(ll u,ll v){
        ll ans=INT_MIN;
        while(1){
            ll x=chain[u];
            ll y=chain[v];
            if(x==y){
                ll l=label[u];
                ll r=label[v];
                if(l>r) swap(l,r);
                ans=max(ans,query(1,0,n-1,l,r).maxi);
                return ans;
            }
            if(depth[x]>depth[y]){
                ans=max(ans,query(1,0,n-1,label[x],label[u]).maxi);
                u=par[x];
            }
            else{
                ans=max(ans,query(1,0,n-1,label[y],label[v]).maxi);
                v=par[y];
            }
        }
    }
};
void solve(){
    cin>>n>>q;
    rep(i,n)    cin>>arr[i];
    rep(i,n-1){
        ll a,b;
        cin>>a>>b;
        g[a].EB(b);
        g[b].EB(a);
    }
    hld t;
    // pr("Teri");
    while(q--){
        ll op;
        cin>>op;
        if(op==1){
            ll nn,val;
            cin>>nn>>val;
            arr[nn-1]=val;
            t.update(1,0,n-1,t.label[nn],val);
        }
        else{
            ll a,b;
            cin>>a>>b;
            cout<<t.query_path(a,b)<<" ";
            // cerr<<endl;
        }
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