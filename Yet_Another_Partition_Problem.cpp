#include <bits/stdc++.h>
using namespace std;

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

set<int> sub;

int lower(int x)
{
    auto it = sub.upper_bound(x);
    it--;
    return (*it);
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    sub.insert(1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if ((i > 1) && (a[i] % a[i - 1] != 0))
            sub.insert(i);
    }

    int query, idx;

    while (q--)
    {
        cin >> query >> idx;
        if (query == 1)
        {
            cin >> a[idx];
            if (idx > 1)
            {
                if ((lower(idx) == idx) && (a[idx] % a[idx - 1] == 0))
                    sub.erase(idx);
                else if ((lower(idx) < idx) && (a[idx] % a[idx - 1] != 0))
                {
                    sub.insert(idx);
                }
            }
            if (idx < n)
            {
                if ((lower(idx + 1) > idx) && (a[idx + 1] % a[idx] == 0))
                    sub.erase(idx + 1);
                else if ((lower(idx + 1) <= idx) && (a[idx + 1] % a[idx] != 0))
                {
                    sub.insert(idx + 1);
                }
            }
        }
        else
        {
            cout << lower(idx) << endl;
        }
    }
}

int main()
{
    FIO;
    OJ;
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}