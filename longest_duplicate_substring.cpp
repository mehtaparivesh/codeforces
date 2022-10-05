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
string f(string s)
{
    ll ans = 0;
    string temp;
    ll startIndex;
    ll low = 0, high = s.size();
    while (low <= high)
    {
        ll mid = mid(low, high);
        ll x = power(31, mid - 1, mod);
        unordered_map<ll, ll> hashes;
        bool found = 0;
        ll hash = 0, p = 31;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s.size() - i > mid)
            {
                hash = (hash - (s[i + mid] - 'a' + 1) * x + mod) % mod;
            }

            hash = (hash * p) % mod;
            hash = (hash + (s[i] - 'a' + 1)) % mod;
            if (s.size() - i > mid and hashes.find(hash) != hashes.end())
            {
                found = true;
                startIndex = i;
                break;
            }
            if (s.size() - i > mid)
                hashes[hash]++;
        }
        if (found)
        {
            ans = mid;

            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << startIndex << " " << ans << endl;

    return ans == 0 ? "" : s.substr(startIndex, ans);
}

int main(int argc, char const *argv[])
{
    file_i_o();
    string s;
    cin >> s;
    cout << f(s) << endl;
    return 0;
}