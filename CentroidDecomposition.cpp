struct CentroidDecomposition {
    vector<set<ll>> tree; // it's not vector<vector<ll>>!
    vector<ll> dad;
    vector<ll> sub;
    vector<vector<ll>> ctree;
    ll root_centroid;

    CentroidDecomposition(vector<set<ll>> &tree) : tree(tree) {
        ll n = tree.size();
        dad.resize(n);
        sub.resize(n);
        ctree.resize(n);
        build(1, -1);
        build_ctree(n);
    }

    void build(ll u, ll p) {
        ll n = dfs(u, p); // find the size of each subtree
        ll centroid = dfs(u, p, n); // find the centroid
        if (p == -1) p = centroid; // dad of root is the root itself
        dad[centroid] = p;

        // for each tree resulting from the removal of the centroid
        vector<ll> child;
        for(auto v:tree[centroid])  child.push_back(v);
        for (auto v : child){
            tree[centroid].erase(v), // remove the edge to disconnect
            tree[v].erase(centroid), // the component from the tree
            build(v, centroid);
        }
    }

    ll dfs(ll u, ll p) {
        sub[u] = 1;

        for (auto v : tree[u])
            if (v != p) sub[u] += dfs(v, u);

        return sub[u];
    }

    ll dfs(ll u, ll p, ll n) {
        for (auto v : tree[u])
            if (v != p and sub[v] > n/2) return dfs(v, u, n);

        return u;
    }

    void build_ctree(ll n){
        for(ll i=1;i<n;i++){
            if(dad[i]!=i){
                ctree[i].push_back(dad[i]);
                ctree[dad[i]].push_back(i);
            }
            else root_centroid=i;
        }
    }
};
