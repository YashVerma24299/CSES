// BRUTE LOGIC

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
 
// signed  main() {     // even + odd
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
 
//     int n;
//     cin>>n;
    
//     while(n--){
//         int a,b;
//         cin>>a>>b;
 
//         if(a==b){
//             if(a&1){
//                 int val=a*a;
//                 cout<<val-(a-1)<<endl;
//             }else{
//                 int val=(a-1)*(a-1);
//                 val++;
 
//                 cout<<val+(a-1)<<endl;
//             }
//         }
//         else if(a<b){
//             if(b&1){
//                 int val=b*b;
//                 cout<<val-(a-1)<<endl;
//             }else{
//                 int val=(b-1)*(b-1);
//                 val++;
//                 cout<<val+(a-1)<<endl;
//             }
//         }
//         else{
//             if(a&1){
//                 int val=a*a;
//                 int range=1+(a-1)*2;
//                 cout<<val-(range-b)<<endl;
//             }else{
//                 int val=(a-1)*(a-1);
//                 val++;
//                 int range=1+(a-1)*2;
//                 cout<<val+(range-b)<<endl;
//             }
//         }
//     }
//     return 0;
// }


// OPTIMAL
#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed  main() {     // even + odd
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin>>n;
    
    while(n--){
        int a,b;
        cin>>a>>b;
 
        int m=max(a,b);
        int base=m*m;
        int ans=0;
 
        if(m%2==0){
            if(a==m){
                ans=base-(b-1);
            }else{
                ans=(m-1)*(m-1) + a;
            }
        }
        else{
            if(a==m){
                ans=(m-1)*(m-1) + b;
            }
            else{
                ans = base-(a-1);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
