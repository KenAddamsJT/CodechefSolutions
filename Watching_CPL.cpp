#include <bits/stdc++.h>
using namespace std;

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int k;
int dp[8001][8001];

int boxAdd(int h1, int h2, map<int, int, greater<int>> &boxes, int used)
{
    if ((h1 >= k) && (h2 >= k))
        return used;
    if (boxes.size() == 0)
        return INT_MAX;
    if (dp[h1][h2] != 0)
    {
        return dp[h1][h2];
    }
    int big = boxes.begin()->first;
    if (boxes[big] == 1)
    {
        boxes.erase(big);
    }
    else
    {
        boxes[big]--;
    }

    int c1 = INT_MAX;
    int c2 = INT_MAX;
    if (h1 < k)
    {
        c1 = boxAdd(h1 + big, h2, boxes, used + 1);
    }
    if (h2 < k)
    {
        c2 = boxAdd(h1, h2 + big, boxes, used + 1);
    }
    boxes[big]++;
    return dp[h1][h2] = min(c1, c2);
}

void solve()
{
    memset(dp, 0, sizeof(dp));
    int n, t;
    cin >> n >> k;
    map<int, int, greater<int>> boxes;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        if (t > k)
            boxes[k]++;
        else
            boxes[t]++;
    }
    int b = boxAdd(0, 0, boxes, 0);
    if (b == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << b << endl;
    }
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