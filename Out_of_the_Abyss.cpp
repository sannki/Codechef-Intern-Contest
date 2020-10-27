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
const int INF = 1e10 - 1;
vector<int> v[100005];

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        int lev[100005];
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++)
        {
            v[i].clear();
        }

        int a, b;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }

        for (int i = 1; i <= n; i++)
            lev[i] = INF;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        while (!pq.empty())
            pq.pop();
        //pq.push({0,1});
        //lev[1]=0;
        for (int i = 0; i < k; i++)
        {

            cin >> x;
            pq.push({0, x});
            lev[x] = 0;
        }
        while (!pq.empty())
        {
            int curr = pq.top().second;
            int curr_d = pq.top().first;
            pq.pop();
            //if (curr_d != lev[curr]) continue;
            if (curr_d > lev[curr])
                continue;
            for (auto it : v[curr])
            {
                if ((curr_d + 1) < lev[it])
                {
                    //cout<<curr_d+it.second<<" ";
                    lev[it] = curr_d + 1;
                    pq.push({lev[it], it});
                }
            }
        }
        int q;
        cin >> q;
        while (q--)
        {
            cin >> x;
            if (lev[x] == INF)
                cout << "-1" << endl;
            else
                cout << lev[x] << endl;
        }
    }
}