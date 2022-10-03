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
    vector<int> f(n);
    for (int i = 0; i < n; i++)
        cin >> f[i];
    int fuel = f[0];
    f[0] = 0;
    int i = 0;
    while (fuel)
    {
        i++;
        fuel--;
        fuel += f[i % n];
        if (i < n)
            f[i] = 0;
    }
    cout << i << endl;
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