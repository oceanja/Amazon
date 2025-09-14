************************************ APPROACH (DFS) **********************************
“We’re given an n x n adjacency matrix isConnected, where isConnected[i][j] = 1 means city i is directly 
connected to city j. Provinces are just connected components in this undirected graph. 
So the task reduces to: how many connected components are there?

My plan is classic graph traversal: keep a visited array; loop i from 0..n-1; if i isn’t visited yet,
that means we’ve found a new province → run a DFS/BFS from i to mark its entire component as visited;
increment the count. Repeat. The number of times I start a new traversal is exactly the number of provinces.”

🧠 About the code:
You first convert the adjacency matrix to an adjacency list adj, then run DFS to mark all reachable nodes.
The DFS is standard: mark u visited, recurse to all unvisited neighbors.

In the outer loop, every time you find an unvisited node, you start a DFS and increment cnt. That cnt is the number of provinces.

Two small implementation notes you can mention if asked:

The matrix is symmetric and includes self-edges (isConnected[i][i] == 1), so when building adj,
you’ll push both i→j and j→i for each 1. That’s fine but redundant; it still works.

You can skip building adj entirely and DFS directly over the matrix row isConnected[u][*] to save memory (iterate v=0..n-1 and 
recurse if isConnected[u][v]==1 && !vis[v]).

⏱ Complexity (and how I evaluate it)

Reading the matrix: You look at all n² entries → O(n²).

DFS total work: Each edge is considered a constant number of times; with a matrix representation,
checking neighbors is also O(n²) in the worst case.

Overall time: O(n²). (I count matrix scans: building adj is n²; DFS via adj is O(n + m) but m can be O(n²) for dense graphs; net O(n²).)

Space:

With an adjacency list you can use up to O(n²) in the worst case (dense graph), plus O(n) for visited and recursion stack.

If you avoid building adj and traverse the matrix directly, extra space is O(n).






class Solution {
public:

void dfs(vector<vector<int>> &adj,int u, vector<bool> &vis){
    vis[u]=true;

    for(auto &neigh:adj[u]){
        if(!vis[neigh]){
            dfs(adj,neigh,vis);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();

        vector<vector<int>> adj(n);
        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> vis(n,false);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,i,vis);
                cnt++;
            }
        }

        return cnt;
    }
};
************************************ APPROACH (BFS) **********************************

Step 1 – Understanding the problem
“The problem is basically asking us to find the number of provinces, where a province is a group of cities 
that are directly or indirectly connected. In graph terms, we’re given an adjacency matrix for an undirected graph, 
and we need to count how many connected components there are.”

Step 2 – First intuition
“My first instinct is to think of it as: every time I see an unvisited city, that must belong to a new province. 
From there, I need to traverse all the cities that are connected to it, directly or indirectly, 
and mark them as visited. That way, they won’t be counted again when I continue scanning.”

Step 3 – Choosing BFS
“To explore all reachable nodes from a given start, I can use either DFS or BFS. Here I chose BFS:

Whenever I find an unvisited node i, I increment my province count (cnt++).

Then I push it into a queue and perform BFS, marking all nodes reachable from i as visited.

When the BFS finishes, I know the entire connected component has been explored.

At the end, the number of times I launched a BFS is exactly the number of provinces.”

Step 4 – How BFS works in the adjacency matrix
“In BFS, I pop a node from the queue, then scan its row in the adjacency matrix. 
If adj[node][v] == 1 and v hasn’t been visited yet, I push v into the queue and mark it as visited. 
This ensures I cover all direct and indirect neighbors of the starting node.”

Step 5 – Complexity

Time complexity: The adjacency matrix has V × V entries. In the worst case, BFS will scan the 
full matrix once across all traversals, so time is O(V²).

Space complexity: We store a visited array of size V and a queue that in the worst case can hold V elements, so space is O(V).


    
class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        int cnt = 0;
        vector<bool> vis(V, false);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                cnt++; 
                queue<int> q;
                q.push(i);
                vis[i] = true;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int v = 0; v < V; v++) {
                        if (adj[node][v] == 1 && !vis[v]) {
                            q.push(v);
                            vis[v] = true;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};
