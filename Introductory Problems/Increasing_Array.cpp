#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>v,vv;
void solve(){
    int n,ans=0;
    cin>>n;
 
    v.resize(n,0);
    vv.resize(n,0);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
 
    for(int i=1; i<n; i++){
        if(v[i]<v[i-1]){
            ans+=v[i-1]-v[i];
            v[i]=v[i-1];
        }
    }  
 
    cout<<ans<<endl;
    return;
}
 
signed  main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}