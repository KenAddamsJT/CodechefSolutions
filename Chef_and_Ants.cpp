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
    ll n, m, t;
    cin >> n;
    vector<vector<ll>> lines(n);
    map<int, int> mp;
    for (ll i = 0; i < n; i++)
    {
        cin >> m;
        for (ll j = 0; j < m; j++)
        {
            cin >> t;
            lines[i].push_back(t);
            mp[abs(t)]++;
        }
    }
    ll ans = 0;
    for (auto m : mp)
    {
        ans += (m.second > 1);
    }

    for (auto line : lines)
    {
        vector<ll> neg, pos;
        for (auto ant : line)
        {
            if (ant < 0)
                neg.push_back(ant);
            else
                pos.push_back(ant);
        }
        reverse(pos.begin(), pos.end());

        while (true)
        {
            ll closest;
            if (neg.empty() and pos.empty())
                break;
            else if (neg.empty())
                closest = pos.back();
            else if (pos.empty())
                closest = neg.back();
            else
                closest = (abs(neg.back()) < pos.back()) ? neg.back() : pos.back();
            if (closest < 0)
            {
                if (mp[abs(closest)] > 1)
                    ans += neg.size() - 1;
                else
                    ans += pos.size();
                neg.pop_back();
            }

            else
            {
                if (mp[closest] > 1)
                    ans += pos.size() - 1;
                else
                    ans += neg.size();
                pos.pop_back();
            }
        }
    }
    cout << ans << endl;
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