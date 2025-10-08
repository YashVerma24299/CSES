#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void solve(){
    int n,q;
    cin>>n>>q;
    
    vector<string>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    vector<vector<int>>prefix(n+1,vector<int>(n+1,0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(v[i-1][j-1]=='*'){
                prefix[i][j]=1+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
            }
            else{
                prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
            }
        }
    }

    while(q--){
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;

        cout<<prefix[y2][x2]-prefix[y1-1][x2]-prefix[y2][x1-1]+prefix[y1-1][x1-1]<<endl;
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
