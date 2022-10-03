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
    vector<int> num(4);
    for (int i = 0; i < 4; i++)
        cin >> num[i];
    for (int i = 1; i < 16; i++)
    {
        int ans = 0;
        bitset<4> b(i);
        for (int j = 0; j < 4; j++)
        {
            if (b[j] == 1)
                ans += num[j];
        }
        if (ans == 0)
        {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
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