/*
    Author : Sanjay Keshwar
*/

/*
    Out of the Abyss 
    Problem Code: ISTHSBFS

 
Statement:
In a far away Galaxy of Tilky Way, there was a planet Tarth where the sport of Tompetitive Toding was very popular. According to legends, there lived a setter who loved giving optimized Dijkstra and Floyd Warshall algorithms in TCDSAP exams.

Commander Tresdin, having obtained stones, must hurry out of the abyss to save Stonehall! The abyss can be represented as an unweighted graph G containing N nodes and M edges. The abyss is chaotic, and hence G can be disconnected as well. K out of these N nodes are special nodes which have a portal to escape from the abyss.

Commander Tresdin met Rubik, the Grand Mage, who offered to help teleport her to the nearest portal. But for that, he needs to know the distance to the nearest portal (that is, the minimum number of edges that have to be traversed)! Hence, given Q queries, each giving a node u, i.e. the Node where Commander Tresdin and Rubik are, print the distance to reach the nearest special node. Print −1 if its not possible to reach a special node from their starting point.

′′We shall meet again after your conquest against the abyssal fire.′′
−Rubik
Input:
The first line contains T− Number of test cases in a file.
The first line of each test case has 3 integers, N, M and K, denoting number of nodes, number of edges, and number of special nodes respectively.
Next M lines have 2 integers each - u v - denoting that there is an (undirected) edge between u and v.
Next line has K space separated integers denoting the special nodes.
Next line has a single integer Q - the number of queries.
Next Q lines contain 1 integer each - u - the starting node for Commander Tresdin.
Output:
For every query, −1 if its not possible to reach any special node by travelling along the given edges starting from node u. Else, print the distance to the nearest special node.

Constraints
1≤T≤1000
1≤N,Q,K≤105
1≤u,v≤N
1≤M≤2.5∗105
Sum of N over all T is ≤106
Sum of Q over all T is ≤106
Sum of M over all T is ≤2.5∗106
G does not have self loops or multiple edges.
Subtasks
20% points - N,Q≤100,M≤200.
80% points - Original Constraints
Sample Input:
1
5 3 3
1 2
1 3
2 3
1 3 5
5
1
2
3
4
5
Sample Output:
0
1
0
-1
0
EXPLANATION:
Nodes 1, 3 and 5 themselves are special nodes and hence the minimum distance to a special node is 0 (i.e. as Commander Tresdin already starts at a special node, she needs not travel any further to reach one).
From Node 2, we can travel an edge to reach Node 1 or Node 3, both at distance of 1.
Node 4 is disconnected from all special nodes.. Starting from Node 4, we cannot reach any special node. Hence −1 is printed.
*/

/*Code*/
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