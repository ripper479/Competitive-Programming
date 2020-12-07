vector<ll> lps(string s){       //Longest proper prefix==Longest proper suffix
    vector<ll> ans(s.size(),0);
    ll i=1,len=0;
    while(i<s.size()){
        if(s[i]==s[len]){
            len++;
            ans[i]=len;
            i++;
        }
        else{
            if(len>0){
                len=ans[len-1];
            }
            else{
                ans[i]=0;
                i++;
            }
        }
    }
    return ans;
}
