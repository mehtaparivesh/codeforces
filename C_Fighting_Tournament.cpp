#include <bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define ld long double
#define mod 1000000007
#define inf 1e18
#define endl "\n"
#define pb emplace_back
#define vi vector<ll>
#define vs vector<string>
#define pii pair<ll, ll>
#define ump unordered_map
#define mp map
#define pq_max priority_queue<ll>
#define pq_min priority_queue<ll, vi, greater<ll>>
#define ff first
#define ss second
#define mid(l, r) (l + (r - l) / 2)
#define loop(i, a, b) for (ll i = (a); i <= (b); i++)
#define looprev(i, a, b) for (ll i = (a); i >= (b); i--)
#define logarr(arr, a, b)           \
    for (ll z = (a); z <= (b); z++) \
        cout << (arr[z]) << " ";    \
    cout << endl;

// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
ll power(long long x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

long long modInverse(unsigned long long n,
                     ll p)
{
    return power(n, p - 2, p);
}

unsigned long long nCrModPFermat(unsigned long long n,
                                 ll r, ll p)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    long long fac[n + 1];
    fac[0] = 1;
    for (ll i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}
void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    ll n, q;
    cin >> n >> q;

    deque<ll> deq(n);
    map<ll, ll> VALUES;
    for (ll i = 0; i < n; i++)
    {
        cin >> deq[i];
        VALUES[deq[i]] = i + 1;
    }

    map<ll, pair<ll, ll>> mp;
    for (ll RNDNND = 1;; RNDNND++)
    {
        ll f = deq.front();
        deq.pop_front();
        ll s = deq.front();
        deq.pop_front();

        if (f == n || s == n)
        {
            mp[VALUES[n]] = {RNDNND, INT_MAX};
            break;
        }
        if (mp.find(VALUES[max(f, s)]) == mp.end())
        {
            mp[VALUES[max(f, s)]] = {RNDNND, RNDNND};
        }
        else
        {
            mp[VALUES[max(f, s)]].ss = RNDNND;
        }

        deq.push_back(min(f, s));
        deq.push_front(max(f, s));
    }

    while (q--)
    {
        ll i, x;
        cin >> i >> x;

        if (mp.find(i) == mp.end())
        {
            cout << 0 << '\n';
        }
        else
        {
            auto [l, r] = mp[i];
            if (l <= x)
            {
                cout << min(x, r) - l + 1 << endl;
            }
            else
            {
                cout << 0 << '\n';
            }
        }
    }
}
signed main()
{
    file_i_o();
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}