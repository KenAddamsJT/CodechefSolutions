#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

void solve()
{
    ll n,res = INT_MAX;
        cin>>n;
        string s;
        cin>>s;
        vector<int>v1(n,0),v2(n,0);
        rep(i,0,n){
            if(s[i] == '(') v1[i]++;
            if(i>0) v1[i] += v1[i-1];
        }
        rev_rep(i,n-1,-1){
            if(s[i] == ')') v2[i]++;
            if(i<n-1) v2[i] += v2[i+1];
        }
        rep(i,0,n) res = min(res,n - 2*min(v1[i],v2[i]));
        cout<<res<<"\n";
}

int main()
{
    FIO;
    //OJ;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
