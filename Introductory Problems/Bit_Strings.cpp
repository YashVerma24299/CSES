#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;
 
signed  main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin>>n;
 
    int ans=1;
    while(n--){
        ans=ans<<1;
        ans=ans%mod;
    }
 
    cout<<ans%mod<<endl;
 
    return 0;
}