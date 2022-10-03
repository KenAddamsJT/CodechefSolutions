#include <bits/stdc++.h>
using namespace std;

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

bool canConstruct(string target, vector<string> wordList, map<string, bool> &memo)
{
    if (memo.find(target) != memo.end())
        return memo[target];

    if (target.empty())
        return true;

    for (auto word : wordList)
    {
        if (target.find(word) == 0)
        {
            string suff = target.substr(word.size());
            if (canConstruct(suff, wordList, memo))
            {
                memo[suff] = true;
                return true;
            }
        }
    }

    memo[target] = false;
    return false;
}

int main()
{
    FIO;
    OJ;
    map<string, bool> memo;
    string target;
    int n;
    cin >> target;
    cin >> n;
    vector<string> wordList(n);
    for (int i = 0; i < n; i++)
    {
        cin >> wordList[i];
    }
    cout << canConstruct(target, wordList, memo);
    return 0;
}