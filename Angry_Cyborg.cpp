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
    int n, q, l, r;
    cin >> n >> q;
    vector<int> left(n + 2, 0);
    vector<int> right(n + 2, 0);
    vector<int> extra(n + 2, 0);
    while (q--)
    {
        cin >> l >> r;
        left[l]++;
        right[r + 1]++;
        extra[r + 1] += (r - l + 2);
    }
    int occurences = 0;
    int node_count = 0;
    for (int i = 1; i <= n; i++)
    {
        occurences += left[i];
        node_count += occurences;
        occurences -= right[i];
        node_count -= extra[i];
        cout << node_count << " ";
    }
    cout << endl;
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