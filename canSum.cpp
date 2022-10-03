//check if array of numbers can generate given sum
#include <bits/stdc++.h>
using namespace std;

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

bool canSum(int sum, vector<int> arr, map<int, int> &memo)
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
                return memo[remainder];
        }

        else
        {
            memo[remainder] = canSum(remainder, arr, memo);
            if (memo[remainder])
                return memo[remainder];
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
    cin >> sum >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }
    cout << canSum(sum, arr, memo);
    return 0;
}