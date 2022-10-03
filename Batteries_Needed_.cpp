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
    ll n, x, s;
    cin >> n >> x;
    vector<int> batt(n);
    multiset<int, greater<int>> batteries;
    for (int i = 0; i < n; i++)
    {
        cin >> batt[i];
    }
    ll sum = 0;
    int l = n / 2, r = n - 1 - n / 2;
    if (l > r)
        swap(l, r);
    while (l >= 0)
    {
        if (r < n)
        {
            batteries.insert(batt[l]);
            if (l != r)
                batteries.insert(batt[r]);
            r++;
            l--;
            sum += *batteries.begin();
            batteries.erase(batteries.begin());
        }
    }
    if (sum >= x)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
}

int main()
{
    FIO;
    OJ;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}