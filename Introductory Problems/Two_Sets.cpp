#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed  main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin>>n;
 
    int sum=0;
    vector<int>a,b;
    for(int i=1; i<=n; i++){
        sum+=i;
    }
 
    if(sum&1){
        cout<<"NO"<<endl;
        return 0;
    }
    else{
        cout<<"YES"<<endl;
    }
    
    int tar=sum/2;
 
    for(int i=n; i>=1; i--){
        if(i<=tar){
            a.push_back(i);
            tar-=i;
        }else{
            b.push_back(i);
        }
    }
 
    cout<<a.size()<<endl;
    for(auto ele:a){
        cout<<ele<<" ";
    }
    cout<<endl;
 
    cout<<b.size()<<endl;
    for(auto ele:b){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}