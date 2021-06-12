#include <bits/stdc++.h>
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define fo(i, a, n) for (int i = a; i <= n; i++)
#define repll(i, a, n) for (lli i = a; i <= n; i++)
#define mkp make_pair
#define pb emplace_back
#define ff first
#define ss second
#define ll long long
#define lli long long int
#define ii int, int
#define pii pair<int, int>
#define pll pair<long, long>
#define plli pair<long long int, long long int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vlli vector<long long int>
#define vpii vector<pair<int, int>>
#define vplli vector<pair<long long int, long long int>>
#define vvlli vector<vector<long long int>>
#define MAXLL 1e18
#define endl '\n'
#define sp ' '
#define dsort(v) sort(v.begin(), v.end(), greater<int>())
#define asort(v) sort(v.begin(), v.end())
#define uniq(v) v.erase(unique(v.begin(), v.end()), v.end())
#define all(v) v.begin(), v.end()
#define umap unordered_map
#define uset unordered_set
#define sz(x) ((int)(x).size())
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define pr(x) cout << x
#define prsp(x) cout << x << sp
#define prln(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0)
#define read(a, n) \
    rep(i, n)      \
            cin >> \
        a[i];
using namespace std;
const int mod = 1000000007;

//EDITORIAL
// Let there be a subarray (i, j) whose sum is divisible by k
//   sum(i, j) = sum(0, j) - sum(0, i-1)
// Sum for any subarray can be written as q*n + rem where q
// is a quotient and rem is remainder
// Thus,
//     sum(i, j) = (q1 * k + rem1) - (q2 * k + rem2)
//     sum(i, j) = (q1 - q2)k + rem1-rem2

// We see, for sum(i, j) i.e. for sum of any subarray to be
// divisible by n, the RHS should also be divisible by k.
// (q1 - q2)k is obviously divisible by k, for (rem1-rem2) to
// follow the same, rem1 = rem2 where
//     rem1 = Sum of subarray (0, j) % k
//     rem2 = Sum of subarray (0, i-1) % k
int32_t main()
{
    fastio;
    ll n, sum = 0;
    cin >> n;
    vector<ll> v(n), mod(n, 0);
    for (ll i = 0; i < n; ++i)
    {
        cin >> v[i];
        sum += v[i];
        mod[((sum % n) + n) % n]++;
    }
    ll res = 0;
    for (ll i = 0; i < n; ++i)
    {
        if (mod[i] > 1)
        {
            res += (mod[i] * (mod[i] - 1) / 2);
        }
    }
    res += mod[0];
    cout << res << endl;
}