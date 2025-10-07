#include <bits/stdc++.h>
using namespace std;
 
int mod=1e9+7;
vector<int>dp;
 
int count(int coin, vector<int>&v){
    if(coin==0) return 0;
    if(dp[coin]!=-2) return dp[coin];
    int minn=1e9;
 
    int n=v.size();
    for(int i=0; i<n; i++){
        if(coin>=v[i]){
            int val=count(coin - v[i], v);
            if(val!=-1)
                minn=min(minn,val+1);
            // else{
            //     minn=1e9;
            // }
        }
       
    }
    return dp[coin]=(minn == 1e9 ? -1 : minn);
}
 
int main() {
    int n,coin;
    cin>>n>>coin;
 
    vector<int>v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    sort(v.rbegin(), v.rend());
 
    dp.resize(coin+1,-2);
    int cnt= count(coin, v);
 
    cout<<cnt<<endl;
 
    return 0;
}