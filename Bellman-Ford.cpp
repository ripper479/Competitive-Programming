class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dis(n+1,1e9);
        dis[k] = 0;
        for(int i=0;i<n-1;i++){
            vector<int> dis_tmp = dis;
            for(auto x:times){
                if(dis_tmp[x[0]]+x[2]<dis_tmp[x[1]]){
                    dis_tmp[x[1]] = dis_tmp[x[0]] + x[2];
                }
            }
            dis = dis_tmp;
        }
        int ans = -1;
        for(int i=1;i<=n;i++)   ans=max(ans,dis[i]);
        if(ans==1e9)    return -1;
        else return ans;
    }

};
