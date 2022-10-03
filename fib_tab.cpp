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

ll fib(int n)
{
    vector<ll> fib(n + 1, 0);
    fib[1] = 1;
    for (int i = 0; i <= n; i++)
    {
        if (i + 1 <= n)
            fib[i + 1] += fib[i];
        if (i + 2 <= n)
            fib[i + 2] += fib[i];
    }
    return fib[n];
}

int main()
{
    FIO;
    OJ;
    int n;
    cin >> n;
    cout << fib(n);
    return 0;
}