#include <bits/stdc++.h>

#define int long long
#define endl '\n'
#define mod 1000000007
#define pb push_back
#define fi first
#define se second
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define rep(i, l, r) for (int i = (int)(l); i <= (int)(r); i++)
#define repi(i, l, r) for (int i = (int)(l); i >= (int)(r); i--)
const int inf = 1e18;

using namespace std;

bool vis[100005];
vi adj[100005];
int maxDist, maxNode;

void dfs(int n, int d)
{
    vis[n] = true;
    if (d > maxDist)
    {
        maxDist = d;
        maxNode = n;
    }

    for (int child : adj[n])
    {
        if (!vis[child])
        {
            dfs(child, d + 1);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    rep(i, 1, n - 1)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    maxDist = -1;
    dfs(1, 0); //src dist = 0
    rep(i, 1, n) vis[i] = false;
    maxDist = -1;
    dfs(maxNode, 0);
    maxDist++;
    cout << maxDist / 2 << endl;

    for (int i = 0; i <= n; i++)
    {
        adj[i].clear();
        vis[i] = false;
    }
    maxDist = -1;
}

int32_t main()
{
    fastIO int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}