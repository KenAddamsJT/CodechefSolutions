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
    int n, k, x, y;
    cin >> n >> k >> x >> y;
    map<int, pair<int, int>> mp;
    if (x == y)
        cout << n << " " << n << endl;
    else
    {
        if ((n - x) > (n - y))
        {
            x += n - y, y = n;
            mp[0] = {x, y};
            y -= n - x, x = n;
            mp[1] = {x, y};
            x -= y, y = 0;
            mp[2] = {x, y};
            y += x, x = 0;
            mp[3] = {x, y};
        }
        else
        {
            y += n - x, x = n;
            mp[0] = {x, y};
            x -= n - y, y = n;
            mp[1] = {x, y};
            y -= x, x = 0;
            mp[2] = {x, y};
            x += y, y = 0;
            mp[3] = {x, y};
        }
        auto elem = mp[(k - 1) % 4];
        cout << elem.first << " " << elem.second << endl;
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