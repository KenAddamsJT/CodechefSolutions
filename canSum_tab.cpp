#include <bits/stdc++.h>
using namespace std;

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

bool canSum(int m, vector<int> v)
{
    vector<bool> pass(m + 1, false);
    pass[0] = true;
    for (int i = 0; i <= m; i++)
    {
        if (pass[i])
        {
            for (auto j : v)
            {
                if (i + j <= m)
                {
                    pass[i + j] = true;
                }
            }
        }
    }
    return pass[m];
}

int main()
{
    FIO;
    OJ;
    int m, n;
    cin >> m >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << canSum(m, v);
    return 0;
}