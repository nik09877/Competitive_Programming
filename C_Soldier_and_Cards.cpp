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
void solve()
{
    int n, p1_size, p2_size;
    vi p1, p2;
    map<pair<vi, vi>, int> mp;
    cin >> n;
    cin >> p1_size;
    rep(i, p1_size)
    {
        int x;
        cin >> x;
        p1.pb(x);
    }
    cin >> p2_size;
    rep(i, p2_size)
    {
        int x;
        cin >> x;
        p2.pb(x);
    }

    mp[{p1, p2}]++;
    int moves(0), i(0), j(0);
    bool good = true;
    while (p1_size != 0 and p2_size != 0)
    {
        if (p1[i] > p2[j])
        {
            p1_size++;
            p2_size--;

            p1.pb(p2[j]);
            p1.pb(p1[i]);
            i++, j++;
            int Size1 = sz(p1);
            int Size2 = sz(p2);
            vi a, b;
            for (int k = i; k < Size1; k++)
            {
                a.pb(p1[k]);
            }
            for (int k = j; k < Size2; k++)
            {
                b.pb(p2[k]);
            }
            if (mp.find({a, b}) == mp.end())
            {
                mp[{a, b}]++;
                moves++;
            }
            else
            {
                good = false;
                break;
            }
        }
        else
        {
            p1_size--;
            p2_size++;

            p2.pb(p1[i]);
            p2.pb(p2[j]);
            i++, j++;
            int Size1 = sz(p1);
            int Size2 = sz(p2);
            vi a, b;
            for (int k = i; k < Size1; k++)
            {
                a.pb(p1[k]);
            }
            for (int k = j; k < Size2; k++)
            {
                b.pb(p2[k]);
            }
            if (mp.find({a, b}) == mp.end())
            {
                mp[{a, b}]++;
                moves++;
            }
            else
            {
                good = false;
                break;
            }
        }
    }
    if (good)
    {
        prsp(moves);
        if (p1_size)
            prln(1);
        else
            prln(2);
    }
    else
        prln(-1);
    return;
}
int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
    {
        solve();
    }
}
