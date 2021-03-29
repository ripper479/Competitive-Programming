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

const ll N = 200005; 
ll nxt[N][20];
ll depth[N],val[N];
vector<ll> g[N];
ll n,q;
void pre(ll nn,ll pp,ll d){
    nxt[nn][0]=pp;
    depth[nn]=d;
    repe(i,1,19){
        nxt[nn][i]=nxt[nxt[nn][i-1]][i-1];
    }
    for(auto x:g[nn]){
        if(x!=pp){
            pre(x,nn,d+1);
        }
    }
}
ll lca(ll u,ll v){
    if(depth[u]<depth[v])   swap(u,v);
    for(ll i=19;i>=0;i--){
        if(((depth[u]-depth[v])>>i)&1){
            u=nxt[u][i];
        }
    }
    if(u==v)    return u;
    for(ll i=19;i>=0;i--){
        if(nxt[u][i]!=nxt[v][i]){
            u=nxt[u][i];
            v=nxt[v][i];
        }
    }
    return nxt[u][0];
}
struct hld{
    vector<ll> parent, depth, heavy, head, pos;
    ll cur_pos;
    ll dfs(ll v) {
        ll size = 1;
        ll max_c_size = 0;
        for (ll c : g[v]) {
            if (c != parent[v]) {
                parent[c] = v, depth[c] = depth[v] + 1;
                ll c_size = dfs(c);
                size += c_size;
                if (c_size > max_c_size)
                    max_c_size = c_size, heavy[v] = c;
            }
        }
        return size;
    }
    void decompose(ll v, ll h) {
        head[v] = h, pos[v] = cur_pos++;
        if (heavy[v] != -1)
            decompose(heavy[v], h);
        for (int c : g[v]) {
            if (c != parent[v] && c != heavy[v])
                decompose(c, c);
        }
    }
    void init() {
        parent = vector<ll>(n);
        depth = vector<ll>(n);
        heavy = vector<ll>(n, -1);
        head = vector<ll>(n);
        pos = vector<ll>(n);
        cur_pos = 0;

        dfs(0);
        decompose(0, 0);
    }
};
struct node{
        ll sum;
        node(){
            sum=0;
        }
    };
struct seg_tree{
    vector<node> t;
    seg_tree(){
        t.resize(4*(n+1));
    }
    node merge(node a,node b){
        node ans;
        ans.sum=a.sum+b.sum;
        return ans;
    }
    void build(ll id,ll l,ll r,vector<ll> &arr){
        if(l==r){
            t[id].sum=val[arr[l]];
            return;
        }
        ll mid=(l+r)/2;
        build(2*id,l,mid,arr);
        build(2*id+1,mid+1,r,arr);
        t[id]=merge(t[2*id],t[2*id+1]);
    }
    void update(ll id,ll l,ll r,ll pos,ll val){
        if(pos<l or pos>r)  return;
        if(l==r){
            t[id].sum=val;
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
};
void solve(){
    cin>>n>>q;
    rep(i,n)    cin>>val[i];
    rep(i,n-1){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        g[a].EB(b);
        g[b].EB(a);
    }
    pre(0,-1,0);
    hld t;
    t.init();
    vector<ll> idx(n);
    rep(i,n)    idx[t.pos[i]]=i;
    seg_tree st;
    st.build(1,0,n-1,idx);
    while(q--){
        ll op;
        cin>>op;
        if(op==1){
            ll p,v;
            cin>>p>>v;
            p--;
            st.update(1,0,n-1,t.pos[p],v);
            val[p]=v;
        }
        else{
            ll a;
            cin>>a;
            a--;
            ll b=0;
            // if(depth[a]<depth[b])   swap(a,b);
            ll mid=lca(a,b);
            ll ans=0;
            ll nn=a;
            node tmp;
            while(1){
                ll top=t.head[nn];
                if(depth[top]<depth[mid])   top=mid;
                ll l=t.pos[nn],r=t.pos[top];
                if(l>r) swap(l,r);
                tmp=st.query(1,0,n-1,l,r);
                ans+=tmp.sum;
                if(top==mid)    break;
                else{
                    nn=t.parent[top];
                }
            }
            cout<<ans<<endl;
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