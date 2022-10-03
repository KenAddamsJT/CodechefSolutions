#include<bits/stdc++.h>
#define rep(i,a,b) for(long long int i=a;i<b;i++)
#define rev_rep(i,a,b) for(long long int i=a;i>b;i--)
#define mod 1000000007
#define bpc(x) __builtin_popcount(x) // used to count no of 1 in binary representation
#define bpcll(x) __builtin_popcountll(x) 
#define ctz(x) __builtin_ctz(x)  // used to count trailing zeros
#define ull unsigned long long int
using namespace std;
typedef long long ll;

//for circular rotation questions, use deque (easy hobe)
//if a number is perfect square -> (int(sqrt(x))*int(sqrt(x))==x) ? 'Yes' : 'No';
//gcd(a,b) = gcd(a,a%b) 
//if a number 'x' is powewr of two, then (x)&(x-1)==0;
// for vector and array, lower bound is - 
// auto it = lower_bound(a.begin(),a.end(),element);
// for set - lower_bound will be -> s.lower_bound(element);
// for set, it=it+1 will not work... it++ will do the same.


int main()    
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
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
    
    



    return 0;
}