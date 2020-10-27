/*
    Author : Sanjay Keshwar
*/

/*
    Chemical Explosion 
    Problem Code: CHEXPLO
 
You are given a road network of a country. The country has n cities in it and n−1 roads connecting them in such a way that there is exactly one way (path) to reach from a city to another. Two cities are said to be neighbours of each other if they are connected via a direct road (i.e. without passing through any other city) between them.

There are some terrorists that want to harm the country. The terrorists have developed two kinds of dangerous chemicals. When these chemicals come in contact with each other, it creates a huge explosion. They plan to infect two cities on the same day, one with chemical A and another with chemical B. With each passing day, these chemicals spread one node at time, to all neighbors of an infected city. That is, on the i-th day, every city which is a neighbor of a city infected with chemical A on day i-1, will now also be infected with chemical A. Similarly with chemical B as well.

To maximize suspense and terror among the public, the terrorists will select the starting two cities, so as to maximize the number of days before the big explosion happens. The big explosion happens when there is a city which is infected by both the chemicals.

Find out the number of days after the initial infections, when the explosion will happen.

Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follow.
The first line of each test case contains an integer n denoting the number of cities in the country.
Each of the next n−1 lines contains two space separated integers u,v denoting that the cities u and v are connected to each other via a direct road.
Constraints
1≤T≤5
1≤n≤105
1≤u,v≤n
Subtasks
For 30% of the score: 1≤n≤1000
Remaining 70%: No extra constraints.
Sample Input
2
3
1 2
2 3
7
1 2
2 3
2 4
1 5
5 6
6 7
Sample Output
1
3
Explanation
Example case 1: If city 1 is infected with chemical A, and city 3 with chemical B, then after one day, city 2 will be infected by both A and B and there will be an explosion. There is no other way in which terrorist could infect the cities such that they get the explosion later than this.

Example case 2: Suppose city 7 is infected with chemical A, and city 3 with chemical B.

Then after one day, city 6 will be infected by both A and city 2 will be affected by B.

After one more day, city 5 will be infected by both A and cities 1 and 3 will be affected by B.

After one more day, city 1 will be infected by both A and city 5 will be affected by B. Now, both cities 1 and 5 have been infected with both the chemical, and so there will be an explosion.

In this scenario, it took 3 days. There is no other way in which terrorist could infect the cities such that they get the explosion later than this. Hence the answer is 3.
*/

/*Code*/
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