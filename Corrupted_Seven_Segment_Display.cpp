#include <bits/stdc++.h>
using namespace std;

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

void solve(vector<bitset<7>> v)
{
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    vector<int> corr;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    for (int i = 0; i < 128; i++)
    {
        bitset<7> b(i);
        int flag = 1;
        for (int j = 0; j < n; j++)
        {
            if ((v[x[j]] & b).count() == y[j])
                continue;
            else
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            corr.push_back(i);
    }
    if (corr.size() == 0)
        cout << "invalid" << endl;
    else
    {
        int min = 8;
        int max = 0;
        for (auto i : corr)
        {
            bitset<7> b(i);
            if (7 - b.count() < min)
                min = 7 - b.count();
            if (7 - b.count() > max)
                max = 7 - b.count();
        }
        cout << min << " " << max << endl;
    }
}

int main()
{
    FIO;
    //OJ;
    vector<bitset<7>> v(10);
    v[0].set();
    v[0].flip(6);

    v[1].set(1);
    v[1].set(2);

    v[2].set();
    v[2].flip(2);
    v[2].flip(5);

    v[3].set();
    v[3].flip(4);
    v[3].flip(5);

    v[4].set();
    v[4].flip(0);
    v[4].flip(4);
    v[4].flip(3);

    v[5].set();
    v[5].flip(1);
    v[5].flip(4);

    v[6].set();
    v[6].flip(1);

    v[7].set(0);
    v[7].set(1);
    v[7].set(2);

    v[8].set();

    v[9].set();
    v[9].flip(4);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve(v);
    }
    return 0;
}