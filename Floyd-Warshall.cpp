class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int kk) {
        vector<vector<int>> dis(n+1,vector<int>(n+1,1e9));
        for(auto x:times){
            dis[x[0]][x[1]] = x[2];
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(dis[i][k] + dis[k][j] < dis[i][j]){
                        dis[i][j] = dis[i][k] + dis[k][j];
                    }
                }
            }
        }
        int ans = -1;
        for(int j=1;j<=n;j++){
            if(j!=kk) ans = max(ans,dis[kk][j]);
        }
        if(ans==1e9)    return -1;
        else return ans;
    }
};
