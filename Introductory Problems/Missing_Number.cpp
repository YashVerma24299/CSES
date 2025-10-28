#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>v;
void solve(){
    int n;
    cin>>n;
    
    v.resize(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
 
    for(int i=1; i<=n; i++){
        if(v[i]!=i){
            cout<<i;
            break;
        }
    }
    cout<<endl;
    return;
}
 
signed  main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}