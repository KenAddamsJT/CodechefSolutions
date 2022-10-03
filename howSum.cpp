#include <bits/stdc++.h>
using namespace std;

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

bool canSum(int sum, vector<int> arr, vector<int> &path, map<int, int> &memo)
{
    // write code to solve problem
    if (sum == 0)
        return true;
    if (sum < 0)
        return false;
    for (auto i : arr)
    {
        int remainder = sum - i;
        if (memo.find(remainder) != memo.end())
        {
            if (memo[remainder])
            {
                path.push_back(i);
                return memo[remainder];
            }
        }

        else
        {
            memo[remainder] = canSum(remainder, arr, path, memo);
            if (memo[remainder])
            {
                path.push_back(i);
                return memo[remainder];
            }
        }
    }
    return false;
}

int main()
{
    FIO;
    OJ;
    int sum, n, temp;
    map<int, int> memo;
    vector<int> arr;
    vector<int> path;
    cin >> sum >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }
    //sort(arr.begin(), arr.end(), greater<int>());
    canSum(sum, arr, path, memo);
    for (auto i : path)
        cout << i << " ";
    return 0;
}