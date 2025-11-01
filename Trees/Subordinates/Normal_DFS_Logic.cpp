#include <bits/stdc++.h>
using namespace std;
#define int long long
 
vector<vector<int>>adj;
vector<int>subordinates;
 
int dfs(int node){
    int cnt=0;
    
    for(auto ele:adj[node]){
        cnt+=1+dfs(ele);
    }
 
    subordinates[node]=cnt;
    return cnt;
}
 
signed  main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin>>n;
 
    adj.resize(n+1);
    subordinates.resize(n+1);
    for(int i=2; i<=n; i++){
        int boss;
        cin>>boss;
        adj[boss].push_back(i);
    }
 
    dfs(1);
 
    for(int i=1; i<=n; i++){
        cout<<subordinates[i]<<" ";
    }
    cout<<endl;
    return 0;
}