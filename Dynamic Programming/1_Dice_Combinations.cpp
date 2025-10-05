#include <bits/stdc++.h>
using namespace std;
 
int mod=1e9+7;
vector<int>dp(6,-1);
 
int count(int sum, int n){
    if(sum>n) return 0;
    if(sum==n) return 1;
 
    if(dp[sum]!=-1) return dp[sum];
 
    int cnt=0;
 
    for(int i=1; i<=6; i++){
        cnt+=count(sum+i, n);
        cnt=cnt%mod;
    }
 
    return dp[sum]=cnt;
}
 
int main() {
    int n;
    cin>>n;
 
    dp.resize(n+1,-1);
    int cnt= count(0,n);
 
    cout<<cnt<<endl;
 
    return 0;
}
