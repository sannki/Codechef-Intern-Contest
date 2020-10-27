/*
    Author : Sanjay Keshwar
*/
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
#define mod 1000000007
#define pb push_back
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define rep(i, l, r) for (int i = (int)(l); i <= (int)(r); i++)
#define repi(i, l, r) for (int i = (int)(l); i >= (int)(r); i--)
const int inf = 1e18;

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vi v(n);
    rep(i, 0, n - 1) cin >> v[i];
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (i & 1)
            sum1 += v[i];
        else
            sum2 += v[i];
    }
    cout << max(sum1, sum2) << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    rep(i, 1, t)
    {
        solve();
    }
}
