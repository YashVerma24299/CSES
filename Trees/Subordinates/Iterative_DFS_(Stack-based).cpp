// Step 1: Build the tree.
// Step 2: Do DFS iteratively and store order.
// Step 3: Reverse to process bottom-up.
// Step 4: Accumulate subordinates using postorder logic.
// Step 5: Print results.


// The DFS traversal order (normal) is a kind of preorder (root before children).

// After reversing it, it becomes a postorder,
// where each parent comes after its children —
// which is a valid topological order for this tree.


// | Concept                | Description                               | In your code                          |
// | ---------------------- | ----------------------------------------- | ------------------------------------- |
// | **Tree**               | Special type of DAG                       | Company structure                     |
// | **DFS order**          | Preorder (root → child)                   | `order.push_back(node)`               |
// | **Reversed DFS order** | Postorder (child → root)                  | `reverse(order.begin(), order.end())` |
// | **Topological order**  | All dependencies (children) before parent | ✅ achieved after reverse              |



#include <bits/stdc++.h>
using namespace std;
#define int long long

signed  main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;


    // Step 1: Build the tree.
    vector<vector<int>>adj(n+1);
    for(int i=2; i<=n; i++){
        int boss;
        cin>>boss;
        adj[boss].push_back(i);
    }


    // Step 2: Do DFS iteratively and store order.
    stack<int>st;
    st.push(1);
    vector<int>order;
    while(!st.empty()){
        int node=st.top();
        st.pop();

        order.push_back(node);
        for(auto ele: adj[node]) st.push(ele);
    }


    // Step 3: Reverse to process bottom-up.
    reverse(order.begin(), order.end());


    // Step 4: Accumulate subordinates using postorder logic.
    vector<int> subordinates(n+1,0);
    for(auto node:order){
        for(auto child: adj[node]){
            subordinates[node]+= 1+ subordinates[child];
        }
    }


    // Step 5: Print results
    for(auto i=1; i<=n; i++){
        cout<<subordinates[i]<<" ";
    }


    return 0;
}
