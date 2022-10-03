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
    int n, m;
    cin >> n >> m;

    map<string, string> chefCountry;
    map<string, int> chefCount;
    map<string, int> countryCount;

    string mChef, mCountry;
    int maxChef = 0;
    int maxCountry = 0;

    for (int i = 0; i < n; i++)
    {
        string chef, country;
        cin >> chef;
        cin >> country;
        chefCountry[chef] = country;
    }

    while (m--)
    {
        string chef;
        cin >> chef;

        chefCount[chef]++;
        countryCount[chefCountry[chef]]++;

        if (chefCount[chef] > maxChef)
        {
            maxChef = chefCount[chef];
            mChef = chef;
        }
        else if (chefCount[chef] == maxChef)
        {
            mChef = min(mChef, chef);
        }
        if (countryCount[chefCountry[chef]] > maxCountry)
        {
            maxCountry = countryCount[chefCountry[chef]];
            mCountry = chefCountry[chef];
        }
        else if (countryCount[chefCountry[chef]] == maxCountry)
        {
            mCountry = min(mCountry, chefCountry[chef]);
        }
    }

    cout << mCountry << endl;
    cout << mChef;
}

int main()
{
    FIO;
    //OJ;
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}