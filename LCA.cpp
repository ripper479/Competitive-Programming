ll nxt[N][20];
ll depth[N];
void dfs(ll nn,ll pp,ll d){
    nxt[nn][0]=pp;
    depth[nn]=d;
    repe(i,1,19){
        nxt[nn][i]=nxt[nxt[nn][i-1]][i-1];
    }
    for(auto x:g[nn]){
        if(x!=pp){
            dfs(x,nn,d+1);
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
