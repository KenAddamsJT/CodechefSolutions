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
    string s;
    cin >> s;
    vector<int> v(26, 0);
    for (auto i : s)
        v[i - 'a']++;
    int pair = 0;
    int ind = 0;
    for (int i = 0; i < 26; i++)
    {
        pair += v[i] / 2;
        ind += v[i] % 2;
    }
    if (ind > pair)
    {
        cout << pair << endl;
    }
    else
    {
        while (ind < pair)
        {
            pair--;
            ind += 2;
        }
        cout << pair << endl;
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