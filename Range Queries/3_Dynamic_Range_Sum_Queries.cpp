#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>v;
vector<int>segment;

void build(int ind, int left, int right){
    if(left==right){
        segment[ind]=v[left];
        return;
    }
    int mid=(left+right)>>1;
    build(2*ind+1, left, mid);
    build(2*ind+2, mid+1, right);

    segment[ind]=segment[2*ind+1] + segment[2*ind+2];
    return;
}

int query(int ind, int left, int right, int req_left, int req_right){
    if(req_left<=left && right<=req_right){
        return segment[ind];
    }

    if(right<req_left || req_right<left){
        return 0;
    }

    int mid=(left+right)>>1;
    int l=query(2*ind+1, left, mid, req_left, req_right);
    int r=query(2*ind+2, mid+1, right, req_left, req_right);

    return l + r;
}

void update(int ind, int left, int right, int pos, int val){
    if(left==right){
        segment[ind]=val;
        return;
    }

    int mid=(left+right)>>1;
    if(pos<=mid) update(2*ind+1, left, mid, pos, val);
    else update(2*ind+2, mid+1, right, pos, val);

    segment[ind]= segment[2*ind+1] + segment[2*ind+2];

    return;
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
        int op,l,r;
        cin>>op>>l>>r; 

        if(op==2){
            l--,r--;
            cout<<query(0,0,n-1,l,r)<<endl;
        }
        else{
            l--;
            update(0,0,n-1,l,r);
        }
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
