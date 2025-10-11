#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>segment,v;

void build(int ind, int left, int right){
    if(left==right){
        segment[ind]=1;
        return;
    }

    int mid=(left+right)/2;
    build(2*ind+1, left, mid);
    build(2*ind+2, mid+1, right);

    segment[ind]=segment[2*ind+1] + segment[2*ind+2]; 
}

int query(int ind, int left, int right, int pos) {

    if(left==right){
        segment[ind]=0;
        return left;
    }

    int mid=(left+right)/2;
    int ans;
    if(segment[2*ind+1]>pos){
        ans=query(2*ind+1, left, mid, pos);
    }else{
        ans=query(2*ind+2,mid+1, right, pos - segment[2*ind+1]);
    }

    segment[ind]=segment[2*ind+1] + segment[2*ind+2];
    return ans;
}
 
void solve(){
    int n;
    cin>>n;
    
    v.resize(n);
    segment.resize(4*n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    build(0,0,n-1);

    int size=n;
    while(size--){
        int a;
        cin>>a;
        int ind=query(0,0,n-1,a-1);
        cout<<v[ind]<<" ";
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
