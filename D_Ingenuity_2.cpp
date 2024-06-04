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
    string s,t = "NSEW";
    int n = nxt();
    cin>>s;

    vector<vi> v(4);
    rep(i, 0, 4) {
        rep(j, 0, n) {
            if(s[j] == t[i]) {
                v[i].pb(j);
            }
        }
    }
    if((sz(v[0])+sz(v[1]))%2 || (sz(v[2])+sz(v[3]))%2) {
        cout<<"NO\n";
        return;
    }
    if(abs(sz(v[0])-sz(v[1]))%2 || abs(sz(v[2])-sz(v[3]))%2) {
        cout<<"NO\n";
        return;
    }
    if(sz(v[0])==1 && sz(v[1])==1 && sz(v[2])==0 && sz(v[3])==0) {
        cout<<"NO\n";
        return;
    }
    if(sz(v[0])==0 && sz(v[1])==0 && sz(v[2])==1 && sz(v[3])==1) {
        cout<<"NO\n";
        return;
    }

    string res(n, 'A');
    rep(i, 0, 4){
        rep(j, 0, sz(v[i]))
        {
            // res[v[i][j]] = (j % 2 ? 'R' : 'H');
            if(j%2){
                if(i<=1) res[v[i][j]] = 'H';
                else res[v[i][j]] = 'R';
            } else {
                if(i<=1) res[v[i][j]] = 'R';
                else res[v[i][j]] = 'H';
            }
        }
    }
    cout<<res<<endl;
}

int32_t main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // std::cout<<std::fixed<<std::setprecision(0);

    int t=1;
    std::cin>>t;
    while(t--) solve();
}