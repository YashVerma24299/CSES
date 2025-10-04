#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void solve(){
    int n,q;
    cin>>n>>q;
 
    vector<int>v(n),prefix(n+1);
    prefix[0]=0;
    for(int i=0; i<n; i++){
        cin>>v[i];
        prefix[i+1]=prefix[i]+v[i];
    }
 
    while(q--){
        int l,r;
        cin>>l>>r;
 
        cout<<prefix[r]-prefix[l-1]<<endl;   
    }
    return;
}
 
signed  main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
