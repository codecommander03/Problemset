#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//										सुखदुःखे समे कृत्वा लाभालाभौ जयाजयौ।।										//
//										ततो युद्धाय युज्यस्व नैवं पापमवाप्स्यसि॥										//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T, class C = std::less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T, class C = std::less_equal<T>>
using ordered_multiset = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

int nxt() {
    int x;
    std::cin >> x;
    return x;
}

#define int            long long int
#define F              first
#define S              second
#define pb             push_back
#define si             std::set <int>
#define vi             std::vector <int>
#define pii            std::pair <int, int>
#define vpi            std::vector <pii>
#define vpp            std::vector <pair<int, pii>>
#define umii           std::unordered_map <string, int>
#define mii            std::map <int, int>
#define mpi            std::map <pii, int>
#define spi            std::set <pii>
#define endl           "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define double         long double
#define que_max        std::priority_queue <int>
#define que_min        std::priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)

void solve(){
    int n = nxt(), k = nxt(), q = nxt();

    vi a(k+1), b(k+1);
    a[0] = b[0] = 0;
    rep(i, 1, k+1) a[i] = nxt();
    rep(i, 1, k+1) b[i] = nxt();

    while(q--){
        int x = nxt(), res = 0;
        int ind = lower_bound(all(a), x) - a.begin();
        if(a[ind] > x) {
            ind--;
            res = b[ind] + (b[ind + 1] - b[ind]) * (x - a[ind]) / (a[ind + 1] - a[ind]);
        } else res = b[ind];
        cout << res << " \n"[q == 0];
        // cout << res<<"("<<ind<<")" << " \n"[q == 0];
    }
}

int32_t main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // std::cout<<std::fixed<<std::setprecision(0);

    int t=1;
    std::cin>>t;
    while(t--) solve();
}