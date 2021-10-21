const ll N = //n
struct node{
    // variables
    node(){
        // initialise variables
    }
};
node t[4*N];
node merge(node a,node b){
    node ans;
    // merge logic
    return ans;
}
void build(ll id,ll l,ll r){
    if(l==r){
        //build logic
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
        // update logic
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
