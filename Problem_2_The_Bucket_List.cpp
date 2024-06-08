#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

//					सुखदुःखे समे कृत्वा लाभालाभौ जयाजयौ॥
//					ततो युद्धाय युज्यस्व नैवं पापमवाप्स्यसि॥

template <typename T, class C = std::less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T, class C = std::less_equal<T>>
using ordered_multiset = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

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

int nxt() {
    int x;
    std::cin >> x;
    return x;
}

struct inst {
    int type;
    int time;
    int buckets = 0;
};

void solve(){
    int n = nxt();
    vector<inst> v;

    rep(i, 0, n){
        int a = nxt(), b = nxt(), c = nxt();
        v.push_back({1, a, c});
        v.push_back({2, b, c});
    }

    sort(all(v), [&](inst a, inst b){
        if(a.time == b.time) return a.type < b.type;
        return a.time < b.time;
    });

    int res = 0, curr = 0;
    for(auto i: v){
        if(i.type == 1){
            curr += i.buckets;
        } else {
            curr -= i.buckets;
        }
        res = max(res, curr);
    }
    cout << res << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);
#endif
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // std::cout<<std::fixed<<std::setprecision(0);

    int t=1;
    // std::cin>>t;
    while(t--) solve();
}