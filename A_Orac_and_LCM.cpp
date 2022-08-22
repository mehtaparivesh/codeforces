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

int main(int argc, char const *argv[])
{
    file_i_o();
    // to checkk again
    // vi sieve(2e5 + 1, 0);
    // for (int i = 0; i < sieve.size(); i++)
    //     sieve[i] = i;
    // for (int i = 2; i * i < sieve.size(); i++)
    // {
    //     if (sieve[i] == i)
    //     {

    //         for (int j = i * i; j < sieve.size(); j += i)
    //         {
    //             if (sieve[j] == j)
    //             {
    //                 sieve[j] = i;
    //             }
    //         }
    //     }
    // }

    // ll n;
    // cin >> n;
    // vi v(n);
    // for (auto &it : v)
    //     cin >> it;
    // ump<ll, vi> u;
    // for (auto it : v)
    // {
    //     ump<ll, ll> temp;
    //     ll x = it;
    //     while (x != 1)
    //     {
    //         temp[sieve[x]]++;
    //         x /= sieve[x];
    //     }
    //     for (auto [key, value] : temp)
    //     {
    //         u[key].push_back(value);
    //     }
    // }
    // ll ans = 1;
    // for (auto &[key, values] : u)
    // {
    //     sort(values.begin(), values.end());

    //     if (values.size() >= n - 1)
    //         ans *= pow(key, values[values.size() == 1 ? 0 : 1]);
    // }

    // cout << ans << endl;

    // youtube solution

    ll n;
    cin >> n;
    vi v(n);
    for (auto &it : v)
        cin >> it;
    vi gcd(n);
    gcd[n - 1] = v.back();
    ll ans = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        gcd[i] = __gcd(v[i], gcd[i + 1]);
    }
    loop(i, 0, n - 2)
    {
        if (i == 0)
            ans = v[i] * gcd[i + 1] / gcd[i];
        else
            ans = __gcd(ans, v[i] * gcd[i + 1] / gcd[i]);
    }
    cout << ans << endl;

    return 0;
}