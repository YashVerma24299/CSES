#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>v,segment,lazy;
 
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
int query(int ind, int left, int right, int pos){
    if(lazy[ind]!=0){
        segment[ind]+=(right-left+1) * lazy[ind];

        if(left!=right){
            lazy[2*ind+1]+=lazy[ind];
            lazy[2*ind+2]+=lazy[ind];
        }
        lazy[ind]=0;
    }

    if(left==right){
        return segment[ind];
    }
 
    int mid=(left+right)>>1;
 
    if(pos<=mid) return query(2*ind+1, left, mid, pos);
    else return query(2*ind+2, mid+1, right, pos);
}
void update(int ind, int left, int right, int req_left, int req_right, int val){
    if(lazy[ind]!=0){
        segment[ind]+=(right-left+1) * lazy[ind];

        if(left!=right){
            lazy[2*ind+1]+=lazy[ind];
            lazy[2*ind+2]+=lazy[ind];
        }
        lazy[ind]=0;
    }

    if(right<req_left || req_right<left){
        return;
    } 
    

    if(req_left<=left && right<=req_right){
        segment[ind]+=(right-left+1)*val;
        if(left!=right){
            lazy[2*ind+1]+=val;
            lazy[2*ind+2]+=val;
        }
        return;
    }
 
    int mid=(left+right)>>1;
    update(2*ind+1, left, mid, req_left, req_right,val);
    update(2*ind+2, mid+1, right, req_left, req_right,val);
    
    segment[ind]=segment[2*ind+1] + segment[2*ind+2];
 
    return;
}
 
void solve(){
    int n,q;
    cin>>n>>q;
 
    v.resize(n);
    segment.resize(4*n,0);
    lazy.resize(4*n,0);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    build(0, 0, n - 1);
 
    while(q--){
        int type;
        cin>>type;
 
        if(type==1){
            int l,r,val;
            cin>>l>>r>>val; 
 
            l--,r--;
            update(0,0,n-1,l,r,val);
        }
        else{
            int pos;
            cin>>pos;
            cout<<query(0,0,n-1,pos-1)<<endl;
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
