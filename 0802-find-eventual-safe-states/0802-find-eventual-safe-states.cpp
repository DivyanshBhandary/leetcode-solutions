class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> rev(n);
        vector<int> indegree(n, 0);

        // Reverse the graph
        for (int i = 0; i < n; i++) {
            for (int node : graph[i]) {
                rev[node].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;

        // Terminal nodes have outdegree 0
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> safe;

        // Kahn's algorithm
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            safe.push_back(node);

            for (int neighbor : rev[node]) {
                indegree[neighbor]--;

                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        sort(safe.begin(), safe.end());

        return safe;
    }
};