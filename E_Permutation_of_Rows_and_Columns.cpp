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

void solve(){
    int n = nxt(), m = nxt(), mn = m * n;
    vector <vector <int>> a(n, vector <int> (m));
    vector <vector <int>> b(n, vector <int> (m));
    
    rep(i, 0, n){
        rep(j, 0, m){
            cin >> a[i][j];
        }
    }
    rep(i, 0, n){
        rep(j, 0, m){
            cin >> b[i][j];
        }
    }

    vi m1x(mn), m1y(mn), m2x(mn), m2y(mn);
    rep(i, 0, n){
        rep(j, 0, m){
            m1x[a[i][j]-1] = i;
            m1y[a[i][j]-1] = j;

            m2x[b[i][j]-1] = i;
            m2y[b[i][j]-1] = j;
        }
    }

    vector<si> vx(mn), vy(mn);
    rep(i, 0, mn){
        vx[m1x[i]].insert(m2x[i]);
        vy[m1y[i]].insert(m2y[i]);
    }

    rep(i, 0, mn){
        if(vx[i].size() > 1 || vy[i].size() > 1){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int32_t main() {
    setIO();
    // std::cout<<std::fixed<<std::setprecision(0);

    int t=1;
    std::cin>>t;
    while(t--) solve();
}