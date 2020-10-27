/*
    Author : Sanjay Keshwar
*/

/*
    Sad Life in Sales 
    Problem Code: SADSALE

 
Preface:
Trees have formed a core part of Graph Theory. Whether it be in form of Red-Black Trees in map, binary tree in heaps etc − trees form the fundamentals of multiple data structures.

What makes trees different from general graphs is the innumerable amount of special properties associated with them, which are otherwise lost in a general graph. Hence, study of Graph Theory feels always incomplete without trees.

Statement:
In a far away Galaxy of Tilky Way, there was a planet Tarth where the sport of Tompetitive Toding was very popular. According to legends, there lived a setter who loved DFS and giving complex Convex Hull Trick problems to unsuspecting candidates in TCDSAP (Todechef Certified Data Structure and Algorithms Program) examination.

Tima has been miserable all day!! She was not able to fetch a lot of sales for Todechef this quarter − even her rivals Tuchika, Teha and Tallavi were far ahead of her.

"They didn't even study sales!!" Tima sobbed. Now, Traveen is a man with heart of gold; hence, he decided to help Tima only because he is a good guy who believes in the power of rainbows, unicorns and goodie-goodie things in world.

He gave Tima the map of Tumbai, in the form of a weighted tree with N nodes, rooted at node R. The nodes are numbered from 1 to N. The edge from node u to node v had a weight w if Tima can pick up w coins by going from u to v and use them to increase her sales result. Tima is happy, and has Q queries, each asking "How many coins can I pick up if I go along the shortest path from node U to V?".

Now, since Traveen was not TCDSAP certified − he cannot find the answer to Tima's query. Its up to you to help him save his day!!

Input:
The first line contains T− Number of test cases in a file.
The first line of each test case has 3 integers − N Q and R - denoting Number of nodes, Number of Queries and the root node respectively.
Next N−1 lines have 3 integers each - u v w - denoting that there is an edge between u to v with w coins.
Next Q lines contain 2 integers - U and V - asking that "How many coins can Tima pick up if she goes from node U to node V".
Note- Input can be huge. Prefer fast IO methods.

Output:
For every query, print the number of coins Tima can pick, on a new line.

Constraints
1≤T≤10000
1≤N,Q≤105
1≤R,u,v,U,V≤N
1≤w≤109
Sum of N, Q over all T is ≤106
Subtasks
15% points - N,Q≤1000.
10% points - Graph is a Path Graph (ie. Line Graph)
15% points - Graph is a Binary Tree (ie. each node has at most two children)
60% points - Original Constraints
Sample Input:
1
3 1 1
1 2 5
1 3 4
2 3
Sample Output:
9
EXPLANATION:
We see that its a simple graph of 3 nodes rooted at Node 1 with Node 1 connected to Node 2 with edge of weight 5, and to node 3 with an edge of weight 4. The query asks coins picked up on going from 2 to 3 which is 5+4=9.
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

vector<int, pair<int, int>> adj[100005];
bool vis[100005];
int level[100005];

int bfs(int x, int y)
{
    queue<int> q;
    q.push()
}
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;

    rep(i, 1, n - 1)
    {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }

    while (q--)
    {
        int x, y;
        cin >> x >> y;
        int ans = bfs(x, y);
        cout << ans << endl;
    }
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
