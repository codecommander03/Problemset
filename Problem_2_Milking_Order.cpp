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
    int n = nxt(), m = nxt(), k = nxt(), cow, pos;

    vi hierarchy(m);
    generate(all(hierarchy) , nxt);

    vi order(n, 0);
    mii mp;
    rep(i, 0, k){
        cin >> cow >> pos;
        if(cow==1) {
            cout << pos;
            return;
        }
        mp[cow] = pos-1;
        order[pos-1] = cow;
    }
    
    if(find(all(hierarchy), 1) != hierarchy.end()){
        int last = 0;

        rep(i, 0, m){
            if(mp.count(hierarchy[i])){
                last = mp[hierarchy[i]];
            } else {
                rep(j, last, n){
                    if(order[j] == 0){
                        last = j;
                        order[j] = hierarchy[i];
                        break;
                    }
                }
            }
            if(hierarchy[i] == 1){
                cout << last + 1;
                return;
            }
        }
    } else {
        int last = n - 1;
        for (int i = m - 1; i >= 0;i--){
            if (mp.count(hierarchy[i]))
                last = mp[hierarchy[i]];
            else
            {
                for (int j = last; j >= 0; j--)
                {
                    if (order[j] == 0)
                    {
                        order[j] = hierarchy[i];
                        last = j;
                        break;
                    }
                }
            }
            if (hierarchy[i] == 1)
            {
                cout << last + 1 << endl;
                return;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(order[i]==0){
            cout<<i+1;
            return;
        }
    }
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
#endif
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // std::cout<<std::fixed<<std::setprecision(0);

    int t=1;
    // std::cin>>t;
    while(t--) solve();
}