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
    int n, k;
    cin >> n >> k;
    vi v(n);
    rep(i, 0, n - 1) cin >> v[i];
    sort(all(v));
    int ans = INT_MAX;
    for (int i = 0; i < n - k + 1; i++)
    {
        if ((v[i + k - 1] - v[i]) < ans)
            ans = v[i + k - 1] - v[i];
    }
    cout << ans << endl;
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
