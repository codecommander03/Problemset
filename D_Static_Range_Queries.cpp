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

struct custom_hash {
static uint64_t splitmix64(uint64_t x) {
// http://xorshift.di.unimi.it/splitmix64.c
x += 0x9e3779b97f4a7c15;
x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
return x ^ (x >> 31);
}

size_t operator()(uint64_t x) const {
static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
return splitmix64(x + FIXED_RANDOM);
}
};

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
#define umii           std::unordered_map <int, int, custom_hash>
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

template <typename T, typename S> constexpr T ifloor(const T a, const S b) { return a / b - (a % b && (a ^ b) < 0); }
template <typename T, typename S> constexpr T iceil(const T a, const S b) { return ifloor(a + b - 1, b); }

void setIO(string name = "") {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

#define set_bits __builtin_popcountll
#define lead_zero __builtin_clzll
#define trail_zero __builtin_ctzll

int nxt() {
    int x;
    std::cin >> x;
    return x;
}

int pow(int base, int exp) {
    int res = 1;
    while (exp > 0) {
        if (exp & 1)
            res = res * base;
        base = base * base;
        exp /= 2;
    }
    return res;
}

int pow(int base, int exp, int mod) {
    int res = 1;
    while (exp > 0) {
        if (exp & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

const int mod = 1000000007;

struct update {
    int l, r, val;
};

void solve(){
    int n = nxt(), q = nxt();
    vector<update> updates(n);
    vector<pii> queries(q);

    vi indices; // all indices of updates and queries

    rep(i, 0, n){
        cin>>updates[i].l>>updates[i].r>>updates[i].val;
        indices.pb(updates[i].l);
        indices.pb(updates[i].r);
    }
    rep(i, 0, q){
        cin>>queries[i].F>>queries[i].S;
        indices.pb(queries[i].F);
        indices.pb(queries[i].S);
    }

    sort(all(indices));
    indices.erase(unique(all(indices)), indices.end()); // unique indices

    auto getCompressedIndex = [&](int a) -> int // returns the index of a in the compressed indices array
    {
        return lower_bound(indices.begin(), indices.end(), a) - indices.begin();
    };

    int n2 = sz(indices);

    vi difference_array(n2+1, 0); // difference array
    vi widths(n2, 0); // with of each interval
    vi interval_value(n2, 0);
    vi prefix_sums(n2, 0);

    rep(i, 0, n){
        difference_array[getCompressedIndex(updates[i].l+1)] += updates[i].val;
        difference_array[getCompressedIndex(updates[i].r)+1] -= updates[i].val;
    }

    rep(i, 0, n2-1){
        widths[i+1] = indices[i+1] - indices[i];
    }

    rep(i, 1, n2){
        interval_value[i] = interval_value[i-1] + difference_array[i];
    }

    rep(i, 1, n2){
        prefix_sums[i] = prefix_sums[i-1] + widths[i] * interval_value[i];
    }

    rep(i, 0, q) {
        cout << prefix_sums[getCompressedIndex(queries[i].S)] - prefix_sums[getCompressedIndex(queries[i].F)] << endl;
    }
}

int32_t main() {
    setIO();
    // std::cout<<std::fixed<<std::setprecision(0);

    int t=1;
    // std::cin>>t;
    while(t--) solve();
}