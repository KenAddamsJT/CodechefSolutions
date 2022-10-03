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
    int n, m, t;
    cin >> n >> m;
    priority_queue<int> M;
    priority_queue<int, vector<int>, greater<int>> N;
    int sumn = 0;
    int summ = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        sumn += t;
        N.push(t);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> t;
        summ += t;
        M.push(t);
    }

    int swaps = 0;
    while ((summ >= sumn) && (N.empty() == false))
    {
        summ -= (M.top() - N.top());
        sumn += (M.top() - N.top());
        M.pop();
        N.pop();
        swaps++;
    }
    if (summ >= sumn)
        cout << -1 << endl;
    else
        cout << swaps << endl;
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