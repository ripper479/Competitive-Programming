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
 
const ll N = 1e5+5;
ll n,q;
struct node{
    ll sum;
    ll lazy;
    node(){
        sum=0;
        lazy=-1;
    }
};
node t[4*N];
node merge(node a,node b){
    node ans;
    ans.sum=a.sum+b.sum;
    return ans;
}
void push(ll id,ll l,ll r){
    if(t[id].lazy!=-1){
        t[id].sum+=t[id].lazy*(r-l+1);
        if(l!=r){
            if(t[2*id].lazy==-1)    t[2*id].lazy=t[id].lazy;
            else t[2*id].lazy+=t[id].lazy;
            if(t[2*id+1].lazy==-1)    t[2*id+1].lazy=t[id].lazy;
            else t[2*id+1].lazy+=t[id].lazy;
        }
        t[id].lazy=-1;
    }
}
void update(ll id,ll l,ll r,ll lq,ll rq,ll val){
    push(id,l,r);
    if(r<lq or l>rq)  return;
    if(lq<=l and rq>=r){
        t[id].lazy=val;
        push(id,l,r);
        return;
    }
    ll mid=(l+r)/2;
    update(2*id,l,mid,lq,rq,val);
    update(2*id+1,mid+1,r,lq,rq,val);
    t[id]=merge(t[2*id],t[2*id+1]);
}
node query(ll id,ll l,ll r,ll lq,ll rq){
    push(id,l,r);
    if(r<lq or l>rq)    return node();
    if(lq<=l and rq>=r) return t[id];
    ll mid=(l+r)/2;
    return merge(query(2*id,l,mid,lq,rq),query(2*id+1,mid+1,r,lq,rq));
}
void solve(){
    cin>>n>>q;
    node t;
    while(q--){
        ll op;
        cin>>op;
        if(op==1){
            ll l,r,v;
            cin>>l>>r>>v;
            r--;
            update(1,0,n-1,l,r,v);
        }
        else{
            ll l,r;
            cin>>l>>r;
            r--;
            t=query(1,0,n-1,l,r);
            cout<<t.sum<<endl;
        }
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