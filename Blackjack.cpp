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
    int n, x, y;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum + v[i] > y)
        {
            int max = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (v[j] < y - sum)
                    max = max(max, v[j]);
            }
            if (u == v.end())
            {
                cout << -1 << endl;
                break;
            }
            else
            {
                u--;
                sum += *u;
                count++;
            }
        }
    }
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