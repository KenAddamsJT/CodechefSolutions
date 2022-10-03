#include <bits/stdc++.h>
using namespace std;

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> N(n);
    vector<int> M(m);
    for (int i = 0; i < n; i++)
    {
        cin >> N[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> M[i];
    }
    auto max = distance(N.begin(), max_element(N.begin(), N.end()));
    auto min = distance(M.begin(), min_element(M.begin(), M.end()));

    for (int i = 0; i < m; i++)
    {
        cout << max << " " << i << endl;
    }
    for (int i = 0; i < n; i++)
    {
        if (i == max)
            continue;
        cout << i << " " << min << endl;
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