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
ll pw[1000000 + 1];
vi generateHash(string &s)
{

    vi dp(s.size());
    ll p = 31;
    ll pow = p;
    dp[0] = s[0] - 'a' + 1;
    pw[0] = 1;
    loop(i, 1, s.size() - 1)
    {

        dp[i] = (dp[i - 1] + (s[i] - 'a' + 1) * pow) % mod;
        pw[i] = pow;
        pow = (pow * p) % mod;
    }

    return dp;
}
ll hashQuery(ll l, ll r, vi &dp)
{
    ll ans = dp[r];
    if (l > 0)
    {
        ans = (ans - dp[l - 1] + mod) % mod;
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    file_i_o();
    string s;
    cin >> s;
    vi dp = generateHash(s);
    ll ans = 0;
    ll n = s.size();
    for (int i = 0; i < s.size() - 1; i++)
    {
        ll pref = dp[i];
        ll suff = hashQuery(n - i - 1, n - 1, dp);
        if ((pref * pw[n - 1 - i]) % mod == suff)
        {
            for (ll j = 1, k = i + 1; k < n - 1; j++, k++)
            {
                ll mid = hashQuery(j, k, dp);
                if ((pref * pw[j]) % mod == mid)
                {
                    ans = i + 1;
                    break;
                }
            }
        }
    }
    string temp = s.substr(0, ans);
    if (ans == 0)
        cout << "Just a legend" << endl;
    else
        cout << temp << endl;
    return 0;
}