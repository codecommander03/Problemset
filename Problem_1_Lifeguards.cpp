// QuangBuiCP
#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "local/debug.hpp"
#else
#define debug(...)
#endif // LOCAL

signed main()
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
#endif // LOCAL

    int n;
    cin >> n;
    vector<int> l(n), r(n), di;
    for (int i = 0; i < n; ++i)
    {
        cin >> l[i] >> r[i];
        di.push_back(l[i]);
        di.push_back(r[i]);
    }
    sort(di.begin(), di.end());
    auto Get = [&di](int x)
    {
        return (int)(lower_bound(di.begin(), di.end(), x) - di.begin());
    };
    int sz = (int)di.size();
    vector<long long> cnt(sz + 1), diff(sz);
    for (int i = 0; i < n; ++i)
    {
        cnt[Get(l[i]) + 1]++;
        cnt[Get(r[i]) + 1]--;
    }
    for (int i = 1; i < sz; ++i)
    {
        cnt[i] += cnt[i - 1];
        diff[i] = di[i] - di[i - 1];
    }
    long long add = 0;
    vector<long long> pref(sz);
    for (int i = 1; i < sz; ++i)
    {
        if (cnt[i] > 0)
        {
            add += diff[i];
        }
        if (cnt[i] == 1)
        {
            pref[i] = diff[i];
        }
        pref[i] += pref[i - 1];
    }
    vector<long long> contributed(n);
    for (int i = 0; i < n; ++i)
    {
        contributed[i] = pref[Get(r[i])] - pref[Get(l[i])];
    }
    cout << add - *min_element(contributed.begin(), contributed.end()) << '\n';

#ifdef LOCAL
    cerr << '\n'
         << clock() << "ms.";
#endif // LOCAL
    return 0;
}