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

ll gridTraveler(int m, int n)
{
    vector<vector<ll>> grid(m + 1, vector<ll>(n + 1, 0));
    grid[1][1] = 1;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (j + 1 <= n)
                grid[i][j + 1] += grid[i][j];
            if (i + 1 <= m)
                grid[i + 1][j] += grid[i][j];
        }
    }
    return grid[m][n];
}

int main()
{
    FIO;
    OJ;
    int m, n;
    cin >> m >> n;
    cout << gridTraveler(m, n);
    return 0;
}