// Logic
// First DFS → find farthest node A from any start (say 1).
// Second DFS → start from A, find farthest node B.
// Distance between A and B = diameter.
 
#include <bits/stdc++.h>
using namespace std;
#define int long long
 
vector<vector<int>>adj;
int farthestNode=0, maxDistance;
 
void dfs(int node, int parent, int dist){
    if(dist>maxDistance){
        maxDistance=dist;
        farthestNode=node;
    }
 
    for(auto ele: adj[node]){
        if(parent!=ele){
            dfs(ele,node, 1+dist);
        }
    }
}
 
signed  main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin>>n;
 
    adj.resize(n+1);
    for(int i=0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    // find farthest node A from any start (say 1).
    maxDistance=-1;
    dfs(1,-1,0);
 
    // start from A, find farthest node B.
    maxDistance=-1;
    dfs(farthestNode,-1,0);
 
    cout<<maxDistance<<endl;
 
    return 0;
}
