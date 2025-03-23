class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);

        // Step 1: Build adjacency list
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int completeComponents = 0;

        // Step 2: Traverse each component using DFS/BFS
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                unordered_set<int> nodes;  // Stores nodes in this component
                int edgeCount = 0;         // Count of edges in this component

                dfs(i, adj, visited, nodes, edgeCount);

                // Step 3: Check if the component is complete
                int k = nodes.size();
                if (edgeCount / 2 == k * (k - 1) / 2) {
                    completeComponents++;
                }
            }
        }

        return completeComponents;
    }

private:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, unordered_set<int>& nodes, int& edgeCount) {
        visited[node] = true;
        nodes.insert(node);

        for (int neighbor : adj[node]) {
            edgeCount++;  // Count each edge (it gets counted twice)
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, nodes, edgeCount);
            }
        }
    }
};