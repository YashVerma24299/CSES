#include <bits/stdc++.h>
using namespace std;
 
int mod=1e9+7;
 
vector<int>dp;
int count(int coin, vector<int>&v){
    if(coin==0) return 1;
 
    if(dp[coin]!=-1) return dp[coin];
 
    int cnt=0,n=v.size();
 
    for(int i=0; i<n; i++){
        if(coin>=v[i]){
            cnt+=count(coin - v[i], v);
            if(cnt>=mod) cnt-=mod;
        }       
    }
    return dp[coin]=cnt;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n,coin;
    cin>>n>>coin;
 
    vector<int>v(n);
    for(int i=0; i<n; i++) cin>>v[i];
 
    dp.resize(coin+1,-1);
    int cnt= count(coin, v);
 
    cout<<cnt<<endl;
 
    return 0;
}
