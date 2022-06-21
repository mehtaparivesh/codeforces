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
#define loop(i, a, b) for (int i = (a); i <= (b); i++)
#define looprev(i, a, b) for (int i = (a); i >= (b); i--)
#define logarr(arr, a, b)            \
    for (int z = (a); z <= (b); z++) \
        cout << (arr[z]) << " ";     \
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
                     int p)
{
    return power(n, p - 2, p);
}

unsigned long long nCrModPFermat(unsigned long long n,
                                 int r, int p)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
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
ll countBits(ll number)
{
    return (ll)log2(number) + 1;
}

int main(int argc, char const *argv[])
{
    file_i_o();

    ll n;
    cin >> n;
    set<ll, greater<ll>> s;

    vi ans(n + 1);
    loop(i, 0, n) s.insert(i);

    while (s.size())
    {
        auto it = *s.begin();
        s.erase(it);
        // cout << *it << " ";
        ll c = countBits(it);
        ll mask = (1 << c) - 1;
        // cout << mask << " ";
        ll tf = (it) ^ mask;

        auto it2 = s.find(tf);
        if (it2 == s.end())
        {
            // cout << "ghapla" << endl;
            continue;
        }
        // cout << *it2 << endl;
        s.erase(*it2);
        ans[tf] = (it);
        ans[it] = (tf);
    }
    ll x = 0;

    loop(i, 0, ans.size() - 1) x += (ans[i] ^ i);
    cout << x << endl;
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
    return 0;
}