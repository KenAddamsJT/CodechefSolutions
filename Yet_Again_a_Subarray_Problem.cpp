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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int len, repeat;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        map<int, int> freq;
        for (int j = i; j < n; j++)
        {
            int m = ceil(((double)k) / (j - i + 1));
            int k1 = ceil(((double)k) / m);
            k1--;
        }
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