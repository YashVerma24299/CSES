#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int ans=0;
 
struct Node {
    // list of connected nodes (general tree)
    vector<int>children;  
};
 
int n;
vector<Node> tree;
 
void buildTree(int n) {
    tree.resize(n + 1); // 1-indexed
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].children.push_back(b);
        tree[b].children.push_back(a); // undirected connection
    }
}
 
int diameter(int node, int parent){
    int max1=0, max2=0;
 
    for(auto child: tree[node].children){
        if(child==parent) continue;
 
        int depth= 1+diameter(child, node);
 
        if(depth>max1){
            max2=max1;
            max1=depth;
        }else if(depth>max2){
            max2=depth;
        }
    }
    ans=max(ans, max1+max2);
    return max1;
}
 
signed  main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n;
 
    buildTree(n);
    diameter(1,-1);
 
    cout<<ans<<endl;
 
    return 0;
}