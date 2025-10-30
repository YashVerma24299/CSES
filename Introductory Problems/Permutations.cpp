#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed  main() {     // even + odd
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin>>n;
    
    if(n==1){
        cout<<1<<endl;
        return 0;
    }
 
    if(n<=3){
        cout<<"NO SOLUTION"<<endl;
        return 0;
    }
 
    for(int i=1; i<=n; i++){
        if(!(i&1)){
            cout<<i<<" ";
        }
    }
    for(int i=1; i<=n; i++){
        if(i&1){
            cout<<i<<" ";
        }
    }
    cout<<endl;
    return 0;
}
