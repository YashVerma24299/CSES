#include <bits/stdc++.h>
using namespace std;
#define int long long
 
vector<vector<int>>adj;
vector<int>dp;
 
int dp_tree(int node){
 
    if(dp[node]!=-1) return dp[node];
 
    int cnt=0;
 
    for(auto ele:adj[node]){
        cnt+=1+dp_tree(ele);
    }
 
    return dp[node]=cnt;
}
 
signed  main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin>>n;
 
    adj.resize(n+1);
    dp.resize(n+1,-1);
    for(int i=2; i<=n; i++){
        int boss;
        cin>>boss;
        adj[boss].push_back(i);
    }
 
    dp_tree(1);
 
    for(int i=1; i<=n; i++){
        cout<<dp[i]<<" ";
    }
    return 0;
}