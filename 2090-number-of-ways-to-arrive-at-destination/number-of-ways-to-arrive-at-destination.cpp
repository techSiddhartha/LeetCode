class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        
        // Graph representation: adjacency list (node -> {neighbor, time})
        vector<vector<pair<int, int>>> graph(n);
        for (auto& road : roads) {
            int u = road[0], v = road[1], time = road[2];
            graph[u].push_back({v, time});
            graph[v].push_back({u, time});
        }
        
        // Min-heap (priority queue) for Dijkstra (time, node)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<long long> dist(n, LLONG_MAX); // Minimum time to reach each node
        vector<int> ways(n, 0); // Number of ways to reach each node with min time
        
        // Start from node 0
        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;
        
        while (!pq.empty()) {
            auto [currTime, u] = pq.top();
            pq.pop();
            
            if (currTime > dist[u]) continue; // Skip outdated paths
            
            for (auto& [v, time] : graph[u]) {
                long long newTime = currTime + time;
                
                // Found a new shortest path
                if (newTime < dist[v]) {
                    dist[v] = newTime;
                    ways[v] = ways[u]; 
                    pq.push({newTime, v});
                } 
                // Found an existing shortest path
                else if (newTime == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        
        return ways[n - 1];
    }
};