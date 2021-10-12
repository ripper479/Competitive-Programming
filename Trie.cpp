struct node{
    node* child[26];
    ll cnt;
    node(){
        cnt=0;
        for(ll i=0;i<26;i++)    child[i]=NULL;
    }
};
struct Trie{
    node* root;
    Trie(){
        root=new node();
    }
    void insert(string s){
        node* curr=root;
        for(ll i=0;i<s.size();i++){
            ll ch = s[i]-'a';
            if(curr->child[ch]==NULL){
                curr->child[ch]=new node();
            }
            curr->cnt+=1;
            curr=curr->child[ch];
        }
        curr->cnt++;
    }
    void erase(string s){
        node* curr=root;
        for(ll i=0;i<s.size();i++){
            ll ch = s[i]-'a';
            curr->cnt-=1;
            if(curr->cnt==0){
                curr->child[ch]=NULL;
                return;
            }
            curr=curr->child[ch];
        }
        curr->cnt--;
    }
    bool search(string s){
        node *curr=root;
        for(ll i=0;i<s.size();i++){
            ll ch= s[i]-'a';
            if(curr->child[ch]==NULL)   return 0;
            curr = curr->child[ch];
        }
        return 1;
    }
};
