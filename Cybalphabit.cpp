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

/*
char nth_letter(int n)
{
    assert(n >= 1 && n <= 26);
    return "abcdefghijklmnopqrstuvwxyz"[n - 1];
}*/

void solve()
{
    int n, k;
    cin >> n >> k;
    if (k < n)
    {
        cout << -1 << endl;
        return;
    }

    else
    {
        multiset<int, greater<int>> arr;
        while (k)
        {
            int c = log2(k);
            arr.insert(c);
            k -= pow(2, c);
        }
        if (arr.size() > n)
        {
            cout << -1 << endl;
            return;
        }
        int extra = n - arr.size();
        int flag = 0;
        while (extra)
        {
            int val = *arr.begin();
            if (val != 0)
            {
                arr.erase(arr.begin());
                arr.insert(val - 1);
                arr.insert(val - 1);
                extra--;
            }
            else
                break;
        }
        if (extra != 0)
        {
            cout << -1 << endl;
            return;
        }
        else
        {
            for (auto i : arr)
                cout << char('a' + i);
            cout << endl;
        }
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