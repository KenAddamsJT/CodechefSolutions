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
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int mismatched = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            mismatched += (matrix[i][j] != matrix[i - 1][j - 1]);
        }
    }
    int q, i, j, e;
    cin >> q;
    while (q--)
    {
        cin >> i >> j >> e;
        i--, j--;
        if (i > 0 && j > 0)
        {
            mismatched -= (matrix[i][j] != matrix[i - 1][j - 1]);
        }
        if (i < n - 1 && j < n - 1)
        {
            mismatched -= (matrix[i][j] != matrix[i + 1][j + 1]);
        }
        matrix[i][j] = e;
        if (i > 0 && j > 0)
        {
            mismatched += (matrix[i][j] != matrix[i - 1][j - 1]);
        }
        if (i < n - 1 && j < n - 1)
        {
            mismatched += (matrix[i][j] != matrix[i + 1][j + 1]);
        }
        if (mismatched == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
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