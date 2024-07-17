#include <bits/stdc++.h>
using namespace std;
string s;
int n, m, q, k, x, w[12], cnt[4099]{0}, ans[4099][101]{0};
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++)
        cin >> w[i];
    for (int i = 0; i < m; i++)
    {
        cin >> s;
        cnt[stoi(s, nullptr, 2)]++; // Store count of duplicates
    }
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < (1 << n); j++)
        {
            int sum = 0, x = i ^ j;
            int y = x ^ ((1 << n) - 1); // y = Wu binary representation
            for (int k = 0; k < n and sum <= 100; k++)
                if (y & (1 << k))
                    sum += w[n - k - 1]; // Wu value
            if (sum <= 100)
                ans[i][sum] += cnt[j]; // Difference array
        }
        for (int j = 0; j < 100; j++)
            ans[i][j + 1] += ans[i][j]; // Prefix sums
    }
    while (q--)
    {
        int k;
        cin >> s >> k;
        int x = stoi(s, nullptr, 2);
        cout << ans[x][k] << '\n'; // O(1)
    }
}