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
    int n;
    cin >> n;
    bitset<4> a;
    for (int i = 0; i < n; i += 4)
    {
        cin >> a;
        cout << char('a' + a.to_ulong());
    }
    cout << endl;
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