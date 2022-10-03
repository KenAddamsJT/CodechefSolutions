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
    int n, temp;
    cin >> n;
    string s;
    string p;
    cin >> s;
    cin >> p;
    if (count(s.begin(), s.end(), '0') == count(p.begin(), p.end(), '0'))
    {
        for (int i = 0; i < n; i++)
        {
            if (s[i] != p[i])
            {
                if (s[i] == '1')
                {
                    temp = 0;
                    if (i < n - 1)
                    {
                        for (int j = i + 1; j < n; j++)
                        {
                            if (s[j] == 0)
                            {
                                s[j] = 1;
                                s[i] = 0;
                                temp = 1;
                                break;
                            }
                        }
                    }
                    if (temp == 0)
                    {
                        cout << "No" << endl;
                        return;
                    }
                }
                if (s[i] == '0')
                {
                    cout << "No" << endl;
                    return;
                }
            }
        }
        cout << "Yes" << endl;
    }
    else
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