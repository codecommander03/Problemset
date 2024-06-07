#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

/////////////////////////////////////////////////////////////////
//				सुखदुःखे समे कृत्वा लाभालाभौ जयाजयौ।।				//
//				ततो युद्धाय युज्यस्व नैवं पापमवाप्स्यसि॥  				//
//////////////////////////////////////////////////////////////

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

void solve(){
    int n = nxt(), m = nxt(), k = nxt(), res = 0;
    vi a(n), b(m);

    rep(i, 0, n) a[i] = nxt();
    rep(i, 0, m) b[i] = nxt();

    // s1 has elements of b that are in both a and b
    // s2 has elements of b that are not in a
    // s3 has elements of a that are not in b
    multiset<int> s1, s2, s3;
    rep(i, 0, m) s2.insert(b[i]);
    rep(i, 0, m){
        if(s2.find(a[i]) != s2.end()){
            s1.insert(a[i]);
            s2.erase(s2.find(a[i]));
        } else s3.insert(a[i]);
    }
    if(sz(s1) >= k)
        res++;
    rep(i, m, n){
        if(s3.count(a[i-m]) > 0){
            s3.erase(s3.find(a[i-m]));
        } else {
            s1.erase(s1.find(a[i-m]));
            s2.insert(a[i-m]);
        }
        if(s2.count(a[i]) > 0) {
            s1.insert(a[i]);
            s2.erase(s2.find(a[i]));
        } else s3.insert(a[i]);
        
        if(sz(s1) >= k)
            res++;
    }
    std::cout << res << endl;
}

int32_t main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // std::cout<<std::fixed<<std::setprecision(0);

    int t=1;
    std::cin>>t;
    while(t--) solve();
}