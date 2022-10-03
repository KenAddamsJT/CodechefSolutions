#include <bits/stdc++.h>
using namespace std;

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

vector<vector<string>> allConstruct(string target, vector<string> wordList, map<string, vector<vector<string>>> &memo)
{
    if (memo.find(target) != memo.end())
        return memo[target];
    if (target.empty())
    {
        vector<vector<string>> empty;
        empty.push_back(vector<string>());
        return empty;
    }

    vector<vector<string>> result;

    for (auto word : wordList)
    {
        if (target.find(word) == 0)
        {
            string suff = target.substr(word.size());
            vector<vector<string>> suffWays = allConstruct(suff, wordList, memo);
            for (auto way : suffWays)
            {
                way.push_back(word);
                result.push_back(way);
            }
        }
    }

    memo[target] = result;
    return result;
}

int main()
{
    FIO;
    OJ;
    map<string, vector<vector<string>>> memo;
    string target;
    int n;
    cin >> target;
    cin >> n;
    vector<string> wordList(n);
    for (int i = 0; i < n; i++)
    {
        cin >> wordList[i];
    }

    vector<vector<string>> result = allConstruct(target, wordList, memo);
    for (auto way : result)
    {
        for (auto word : way)
        {
            cout << word << " ";
        }
        cout << endl;
    }
    return 0;
}