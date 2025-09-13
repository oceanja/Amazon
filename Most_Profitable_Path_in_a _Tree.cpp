

*************************** OPTIMAL APPROACH**************************

“Okay, so Alice starts at 0, Bob starts somewhere else, and both move one step per unit time. Alice wants to maximize how much she collects…
At first glance, my instinct was: maybe I just simulate both of them? But then I realized, Bob doesn’t wander the whole tree — 
he has only one unique path to 0 because it’s a tree. That simplifies things a lot.
So then I thought: if I could somehow know exactly when Bob reaches each node on his path to 0, then Alice could just compare her 
time with his time at every node she visits. That feels like the right piece of information to have.
How do I get that? Well, I can do a DFS starting at Bob. If I eventually hit 0, then every node I touched along the way can be
stamped with the time it took Bob to reach it. And if a branch doesn’t lead to 0, 
I just backtrack and erase those times. That way, after this DFS, I have a nice map of Bob’s arrival times along his path.
Now with Bob’s timings in hand, I started thinking about Alice. 
She can try many different paths because she wants to maximize her income. So I’ll need to explore all root-to-leaf paths for her. While doing this DFS, at each node I just check:
if Alice arrives before Bob, she gets the full amount,
if they arrive at the same time, she gets half,
otherwise she gets nothing.
And whenever she reaches a leaf, I update the maximum income.
So that way, the problem boils down to two DFS traversals: one for Bob to figure out his timeline, and one for Alice to try every path.”

“In terms of complexity, I usually just ask: how many times am I touching each node?
Bob’s DFS visits each node once along possible paths, so O(N).
Alice’s DFS also visits each node once, so another O(N).
And at each node the work is constant — just a couple of comparisons and additions.

So the total time is O(N).

For space, I’m holding the adjacency list and Bob’s map, which are O(N), plus the recursion stack which is at most the tree height O(H). So overall O(N) space.”



  
****** CODE********
class Solution {
public:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> bobMap;
    int aliceIncome;
    bool DFSBob(int curr, int t, vector<bool>&  visited) {
        visited[curr] = true;
        bobMap[curr] = t;

        if(curr == 0) { //reached target
            return true;
        }

        for(auto &ngbr : adj[curr]) {
            if(!visited[ngbr]) {
                if(DFSBob(ngbr, t+1, visited) == true) {
                    return true;
                }
            }
        }

        bobMap.erase(curr);
        return false;
    }

    void DFSAlice(int curr, int t, int income, vector<bool>& visited, vector<int>& amount) {
        visited[curr] = true;

        if(bobMap.find(curr) == bobMap.end() || t < bobMap[curr]) {
            income += amount[curr];
        } else if(t == bobMap[curr]) {
            income += (amount[curr]/2);
        }


        if(adj[curr].size() == 1 && curr != 0) { //leaf node
            aliceIncome = max(aliceIncome, income);
        }


        for(int &ngbr : adj[curr]) {
            if(!visited[ngbr]) {
                DFSAlice(ngbr, t+1, income, visited, amount);
            }
        }

    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size(); 

        aliceIncome = INT_MIN;
        for(vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //DFS on Bob for finding time to reach each node till 0
        int time = 0;
        vector<bool> visited(n, false);
        DFSBob(bob, time, visited);
        
        int income = 0;
        visited.assign(n, false);
        DFSAlice(0, 0, income, visited, amount);

        return aliceIncome;
    }
};
