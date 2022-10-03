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
    int n, k, d, t;
    cin >> n >> k >> d;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        sum += t;
    }
    ll max = sum / k;
    if (max <= d)
        cout << max << endl;
    if (max > d)
        cout << d << endl;
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