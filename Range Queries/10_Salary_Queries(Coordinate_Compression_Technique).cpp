// Method 1: Using LowerBound and UpperBound  (TLE)

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// vector<int>v;
// void solve(){
//     int n,q;
//     cin>>n>>q;
    
//     v.resize(n);
//     multiset<int>s;
//     for(int i=0; i<n; i++){
//         cin>>v[i];
//         s.insert(v[i]);
//     }
 
//     while(q--){
//         int a,b;
//         char symbol;
//         cin>>symbol>>a>>b;
 
//         if(symbol=='?'){
//             auto start=s.lower_bound(a);
//             auto end=s.upper_bound(b);
//             int ans=distance(start,end);
//             cout<<ans<<endl;
//         }else{
//             int val=v[--a];
//             auto it = s.find(val); 
//             if (it != s.end()) {
//                 s.erase(it);
//             }
//             s.insert(b);
//         }
 
//     }
//     cout<<endl;
//     return;
// }
// signed  main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     solve();
//     return 0;
// }



// Method 2: Segment Tree with Coordinate Compression
#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>segment;
  
int query(int ind, int left, int right, int a, int b) {
    if (b < left || right < a) return 0;  // completely outside
    if (a <= left && right <= b) return segment[ind]; // completely inside
    int mid = (left + right) / 2;
    return query(2*ind, left, mid, a, b) + query(2*ind+1, mid+1, right, a, b);
}

void update(int ind, int left, int right, int pos,  int val) {
    if (left == right) {
        segment[ind] += val;
        return;
    }
 
    int mid = (left + right) / 2;
    if (pos <= mid) {
        update(2 * ind , left, mid, pos, val);
    } else {
        update(2 * ind + 1, mid + 1, right, pos, val);
    }
 
    segment[ind] = segment[2 * ind] + segment[2 * ind + 1];
}
 
void solve(){
    int n,q;
    cin>>n>>q;
    //vals -> store all unique possible value and sort into ascending order
    vector<int>vals(n+(2*q));

    // m -> map is used to assign the value from 1 to 10^5 to the "vals"
    unordered_map<int,int>m;
    int k=1;

    // queries -> store the given query
    vector<pair<char, pair<int,int>>>queries;
    

    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
        vals.push_back(v[i]);
    }   
    while(q--){
        int a,b;
        char symbol;
        cin>>symbol>>a>>b; 
        queries.push_back({symbol,{a,b}});
        vals.push_back(a);
        vals.push_back(b);
    }

    // Coordinate Compression
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    
    // Assign the map value
    for(auto ele:vals){
        m[ele]=k;
        k++;
    }


    int size=vals.size();
    segment.resize(4*size, 0);
    for(int i=0; i<n; i++){
        int val=v[i];  // original value
        int req_val=m[val]; // mapped value or new value
        update(1,1,size,req_val, 1);
    }

    for(auto it:queries){
        char ch=it.first;
        int a=it.second.first;
        int b=it.second.second;

        if(ch=='?'){
            int l=m[a];
            int r=m[b];
            if (l > r) swap(l, r);
            cout<<query(1,1,size,l,r)<<endl;
        }
        else{
            a--;
            int l=m[v[a]];
            int r=m[b];
            update(1,1,size,l, -1);
            v[a]=b;
            update(1,1,size,r, +1);
            
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
