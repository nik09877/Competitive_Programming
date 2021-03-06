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

// dp[i][j] represents the probability of getting j heads using first i coins (0 based indexing)
int n;
double p[3000];
double dp[3000][3001];

int32_t main()
{
    fastio;
    cout << fixed << setprecision(10);
    cin >> n;
    read(p, n);
    dp[0][1] = p[0];
    dp[0][0] = 1 - p[0];
    for (int i = 1; i < n; i++)
    {
        //we can get at most i+1 heads using i elelments(0 based indexing)
        for (int j = 0; j <= i + 1; j++)
        {
            //if i get head
            if (j > 0)
                dp[i][j] += p[i] * dp[i - 1][j - 1];

            //if i get tail here
            dp[i][j] += (1 - p[i]) * dp[i - 1][j];
        }
    }
    double ans = 0;
    for (int i = n / 2 + 1; i <= n; i++)
    {
        ans += dp[n - 1][i];
    }
    cout << ans;
}

//TLE
// double getAns(int i, int head_cnt)
// {
//     if (i == n)
//     {
//         int tail_cnt = n - head_cnt;
//         if (tail_cnt >= head_cnt)
//             return 0;
//         return 1;
//     }
//     if (dp[i][head_cnt] < 0.00000001)
//         return dp[i][head_cnt];

//     double x = 0, y = 0;
//     //independent probability (multiplication)
//     x = p[i] * getAns(i + 1, head_cnt + 1);
//     y = (1 - p[i]) * getAns(i + 1, head_cnt);

//     return dp[i][head_cnt] = x + y;
// }