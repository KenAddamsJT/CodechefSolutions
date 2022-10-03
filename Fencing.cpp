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

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;

    map<pair<int, int>, int> plants;
    ll fence = 0;
    ll i, j;

    while (k--)
    {
        cin >> i >> j;
        plants[{i, j}] = 1;
    }

    for (auto x : plants)
    {
        i = x.first.first;
        j = x.first.second;
        fence += 4;
        if (plants.find({i + 1, j}) != plants.end())
        {
            fence--;
        }
        if (plants.find({i - 1, j}) != plants.end())
        {
            fence--;
        }
        if (plants.find({i, j + 1}) != plants.end())
        {
            fence--;
        }
        if (plants.find({i, j - 1}) != plants.end())
        {
            fence--;
        }
    }
    cout << fence << endl;
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