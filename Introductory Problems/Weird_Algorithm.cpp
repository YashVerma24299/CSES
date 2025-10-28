#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    vector<int> nums;
    nums.push_back(n);
 
    while(n!=1){
        if(n%2==0){
            n/=2;
        }else{
            n*=3;
            n+=1;
        }
        nums.push_back(n);
    }
 
    for(auto ele:nums)cout<<ele<<" ";
    cout<<endl;
 
    return 0;
}