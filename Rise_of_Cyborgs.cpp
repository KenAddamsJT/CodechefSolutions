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

/*
attribution:
part of the below function available at 
https://www.geeksforgeeks.org/sum-of-minimum-elements-of-all-subarrays/
*/
int sumSubarrayMins(vector<int> A, int n)
{
    vector<int> left(n);
    vector<int> right(n);
    stack<pair<int, int>> s1, s2;
    // getting number of element strictly larger
    // than A[i] on Left.
    for (int i = 0; i < n; ++i)
    {
        int cnt = 1;
        // get elements from stack until element
        // greater than A[i] found
        while (!s1.empty() && (s1.top().first) > A[i])
        {
            cnt += s1.top().second;
            s1.pop();
        }

        s1.push({A[i], cnt});
        left[i] = cnt;
    }

    // getting number of element larger than A[i] on Right.
    for (int i = n - 1; i >= 0; --i)
    {
        int cnt = 1;

        // get elements from stack until element greater
        // or equal to A[i] found
        while (!s2.empty() && (s2.top().first) >= A[i])
        {
            cnt += s2.top().second;
            s2.pop();
        }

        s2.push({A[i], cnt});
        right[i] = cnt;
    }

    int result = 0;
    for (int i = 0; i < n; ++i)
        result = (result + A[i] * left[i] * right[i]);
    return result;
}
void checkmate()
{
    int n, m;
    int ans = 0;
    cin >> n >> m;
    vector<int> A;
    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        b[i]--;
        ans += a[b[i]];
    }
    for (int i = 0; i < m - 1; i++)
    {
        int L = b[i];
        int R = b[i + 1];
        int mn = INT16_MAX;
        for (int j = L; j <= R; j++)
        {
            mn = min(mn, a[j]);
        }
        A.push_back(mn);
    }
    ans += sumSubarrayMins(A, (int)A.size());
    cout << ans << '\n';
}
int32_t main()
{
    FIO;
    int t = 1;
    cin >> t;
    while (t--)
        checkmate();
    return 0;
}