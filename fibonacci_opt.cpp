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

ll fibonacci(ll n)
{
    static map<ll, ll> memo;
    if (n == 0 || n == 1)
        return n;
    map<ll, ll>::iterator iter = memo.find(n);
    if (iter == memo.end())
    {
        return memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    }
    else
    {
        return iter->second;
    }
}

int main()
{
    FIO;
    OJ;
    ll n;
    cin >> n;
    ll fibo = fibonacci(n);
    cout << fibo;
    return 0;
}