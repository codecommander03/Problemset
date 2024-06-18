#include <bits/extc++.h>
#include <bits/stdc++.h>
/*
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
*/
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define double long double
#define pb push_back
#define sz(x) (int)(x).size()
#define all(v) begin(v), end(v)
#define debug(x) cerr << #x << " = " << x << '\n'
#define LINE cout << "\n-----------------\n"
#define endl '\n'
#define VI vector<int>
#define F first
#define S second
#define MP(a, b) make_pair(a, b)
#define rep(i, m, n) for (int i = m; i <= n; ++i)
#define res(i, m, n) for (int i = m; i >= n; --i)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a *b / gcd(a, b)
#define Case() \
    int _;     \
    cin >> _;  \
    for (int Case = 1; Case <= _; ++Case)
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;
template <typename K, typename cmp = less<K>, typename T = thin_heap_tag>
using _heap = __gnu_pbds::priority_queue<K, cmp, T>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, cmp, T, tree_order_statistics_node_update>;
template <typename K, typename M = null_type, typename cmp = less_equal<K>, typename T = rb_tree_tag>
using _multitree = tree<K, M, cmp, T, tree_order_statistics_node_update>;
const int N = 1e6 + 5, L = 20, mod = 998244353, inf = 1e15 + 5;
#define pii pair<int, int>
void readfile()
{
    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);
}
void solve()
{
    int n;
    cin >> n;
    vector<pii> v(n);
    rep(i, 0, n - 1)
    {
        cin >> v[i].F >> v[i].S;
    }
    multiset<pii> st1, st2;
    rep(i, 0, n - 1)
    {
        st1.insert({v[i].F, v[i].S});
        st2.insert({v[i].S, v[i].F});
    }
    int ans = inf;
    rep(i, 0, 3)
    { // xbegin
        rep(j, 0, 3)
        { // xend
            rep(k, 0, 3)
            { // ybegin
                rep(l, 0, 3)
                { // yend
                    if (i + j + k + l == 3)
                    {
                        vector<pii> tmp;
                        rep(m, 0, i - 1)
                        {
                            auto now = *st1.begin();
                            tmp.pb(now);
                            st1.erase(st1.find(now));
                            st2.erase(st2.find({now.S, now.F}));
                        }
                        rep(m, 0, j - 1)
                        {
                            auto now = *(--st1.end());
                            tmp.pb(now);
                            st1.erase(st1.find(now));
                            st2.erase(st2.find({now.S, now.F}));
                        }
                        rep(m, 0, k - 1)
                        {
                            auto now = *st2.begin();
                            tmp.pb({now.S, now.F});
                            st2.erase(st2.find(now));
                            st1.erase(st1.find({now.S, now.F}));
                        }
                        rep(m, 0, l - 1)
                        {
                            auto now = *(--st2.end());
                            tmp.pb({now.S, now.F});
                            st2.erase(st2.find(now));
                            st1.erase(st1.find({now.S, now.F}));
                        }
                        ans = min(ans, ((*(--st1.end())).F - (*st1.begin()).F) * ((*(--st2.end())).F - (*st2.begin()).F));
                        for (auto m : tmp)
                        {
                            st1.insert(m);
                            st2.insert({m.S, m.F});
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
signed main()
{
    IOS;
    readfile();
    solve();
    return 0;
}