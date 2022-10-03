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
    cin >> n;
    cin >> m;

    vector<int> a;
    vector<int> b;

    stack<int> s;
    set<int> vals;

    s.push(0);

    int inp;
    for (int i = 0; i < n; i++)
    {
        cin >> inp;
        a.push_back(inp);
        s.push(inp);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> inp;
        b.push_back(inp);
    }

    map<int, bool> traversed;

    while (!s.empty())
    {
        int x = s.top();
        s.pop();

        if (traversed.find(x) != traversed.end())
            continue;
        traversed[x] = 1;

        for (auto i : a)
        {
            auto ins = vals.insert(x | i);
            if (ins.second == true)
                s.push(x | i);
        }
        for (auto i : b)
        {
            auto ins = vals.insert(x & i);
            if (ins.second == true)
                s.push(x & i);
        }
    }

    cout << vals.size();
    cout << endl;
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