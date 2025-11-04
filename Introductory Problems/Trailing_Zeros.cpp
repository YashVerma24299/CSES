#include <bits/stdc++.h>
using namespace std;
#define int long long

signed  main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    int ans=0;
    while(n!=0){
        ans+=n/5;
        n/=5;
    }

    cout<<ans<<endl;

    return 0;
}
