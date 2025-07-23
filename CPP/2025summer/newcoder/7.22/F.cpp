// Author: QHZY
// Create_Time: 2025/07/22 12:03:48
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
using ull = unsigned long long;
using ld = long double;
#define double ld
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;
using piii = pair<int, pii>;
#define pb push_back
#define fi first
#define se second
const ll INF = 0x3f3f3f3f3f3f3f3f;
void work(){
    int n,a,b;
    cin>>n>>a>>b;
    if(n<=a){
        cout<<"Sayonara"<<endl;
        return;
    }
    if(n%(a+b)==0||n%(a+b)>a){
        cout<<0<<endl;
        return;
    }
    else{
        int ans=n%(a+b);
        ans=min(ans,a+b-n%(a+b));
        cout<<ans<<endl;
        return;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
        work();
    return 0;
}