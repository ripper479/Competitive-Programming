struct Matrix{
    ll m[2][2];
    Matrix(){
        rep(i,2){
            rep(j,2)    m[i][j]=0;
        }
    }
    void initialize(){
        m[0][0]=1;m[0][1]=1;m[1][0]=1;m[1][1]=0;
    }
    void unitary(){
        rep(i,2)    m[i][i]=1;
    }
    Matrix operator*(Matrix m2){
        Matrix ans;
        rep(i,2){
            rep(j,2){
                rep(k,2){
                    (ans.m)[i][j]=((ans.m)[i][j]+(m[i][k]*(m2.m)[k][j]))%mod;
                }
            }
        }
        return ans;
    }
};
Matrix calc(Matrix a, ll b) {
    Matrix res;
    res.unitary();
    while (b > 0) {
        if (b & 1)
            res = res*a;
        a=a*a;
        b >>= 1;
    }
    return res;
}
ll getNthFib(ll n){
    Matrix t;
    t.initialize();
    t=calc(t,n);
    return t.m[0][1];
}
