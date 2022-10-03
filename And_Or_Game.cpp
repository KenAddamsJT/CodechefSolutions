#include <bits/stdc++.h>
using namespace std;

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

set<int> vals;

map<pair<int, int>, int> _or;
map<pair<int, int>, int> _and;

void operate(vector<int> &a, vector<int> &b, int x, int y, int v)
{
    vals.insert(v);
    if (x >= a.size() && y >= b.size())
        return;
    if (x < a.size())
    {
        _and[{v, a[x]}] = v | a[x];
        operate(a, b, x + 1, y, _and[{v, a[x]}]);
    }
    if (y < b.size())
    {
        _or[{v, b[y]}] = v & b[y];
        operate(a, b, x, y + 1, _or[{v, b[y]}]);
    }
}

void solve()
{
    int n, m;
    cin >> n;
    cin >> m;
    vector<int> a(n);
    vector<int> b(m);
    int v = 0;
    vals.clear();
    int inp;
    for (int i = 0; i < n; i++)
    {
        cin >> inp;
        a.push_back(inp);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> inp;
        b.push_back(inp);
    }
    operate(a, b, 0, 0, 0);
    cout << vals.size();
    cout << endl;
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