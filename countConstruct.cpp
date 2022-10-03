#include <bits/stdc++.h>
using namespace std;

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int countConstruct(string target, vector<string> wordList, map<string, int> &memo)
{
    int count = 0;

    if (target.empty())
        return 1;

    if (memo.find(target) != memo.end())
        return memo[target];

    for (auto word : wordList)
    {
        if (target.find(word) == 0)
        {
            string suff = target.substr(word.size());
            count += countConstruct(suff, wordList, memo);
        }
    }

    memo[target] = count;
    return count;
}

int main()
{
    FIO;
    OJ;
    map<string, int> memo;
    string target;
    int n;
    cin >> target;
    cin >> n;
    vector<string> wordList(n);
    for (int i = 0; i < n; i++)
    {
        cin >> wordList[i];
    }
    cout << countConstruct(target, wordList, memo);
    return 0;
}