struct Disjoint{
    ll len;
    vector<ll> parent;
    vector<ll> rank;
    Disjoint(ll x){
        len=x;
        rep(i,x+1){
            parent.EB(i);
            rank.EB(1);
        }
    }
    ll find(ll x){
        if(parent[x]==x) return x;
        parent[x]=find(parent[x]);
        return parent[x];
    }
    void merge(ll x,ll y){
        ll p_x=find(x);
        ll p_y=find(y);
        if(p_x==p_y)    return;
        if(rank[p_x]<rank[p_y]){
            parent[p_x]=p_y;
            rank[p_y]+=rank[p_x];
        }
        else{
            parent[p_y]=p_x;
            rank[p_x]+=rank[p_y];
        }
    }
};
