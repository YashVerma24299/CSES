#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>segment,v;

void build(int ind, int left, int right){
    if(left==right){
        segment[ind]=v[left];
        return;
    }

    int mid=(left+right)/2;
    build(2*ind+1, left, mid);
    build(2*ind+2, mid+1, right);

    segment[ind]=max(segment[2*ind+1], segment[2*ind+2]);
}

int query(int ind, int left, int right, int value){
    if(segment[0]<value){
        return 0;
    }

    if(left==right){
        segment[ind]-=value;
        return left+1;
    }

    int mid=(left+right)/2;
    int ans;
    if(segment[2*ind+1]>=value){
        ans=query(2*ind+1, left, mid,value);
    }else{
        ans=query(2*ind+2,mid+1, right, value);
    }

    segment[ind]=max(segment[2*ind+1], segment[2*ind+2]);
    return ans;
}
 
void solve(){
    int n,q;
    cin>>n>>q;
    
    v.resize(n);
    segment.resize(4*n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    build(0,0,n-1);

    while(q--){
        int a;
        cin>>a;
        cout<<query(0,0,n-1,a)<<" ";
    }
    cout<<endl;
    return;
}
 
signed  main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
