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
 
void dfs(int node, int parent, vector<int>& dist){
    for(auto child: tree[node].children){
        if(child==parent) continue;
        dist[child] = dist[node] + 1;   // increase distance
        dfs(child, node, dist); 
    }
}
 
signed  main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n;
    buildTree(n);

    // Step 1: DFS from node 1 to find farthest node A
    vector<int> dist1(n + 1, 0);
    dfs(1, -1, dist1);
    int A = max_element(dist1.begin() + 1, dist1.end()) - dist1.begin();


    // Step 2: DFS from A to find farthest node B
    vector<int> distA(n + 1, 0);
    dfs(A, -1, distA);
    int B = max_element(distA.begin() + 1, distA.end()) - distA.begin();


    // Step 3: DFS from B to get distances from other end
    vector<int> distB(n + 1, 0);
    dfs(B, -1, distB);


    // Step 4: For each node, answer = max(distance from A, distance from B)
    for (int i = 1; i <= n; i++) {
        cout << max(distA[i], distB[i]) << " ";
    }
 
    return 0;
}
