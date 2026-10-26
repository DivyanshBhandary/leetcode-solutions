class Solution {
public:
    bool dfs(int source, int par, int defColor,
             vector<vector<int>>& graph, vector<int>& color) {

        color[source] = defColor;

        for (auto z : graph[source]) {

            if (color[z] == -1) {
                if (dfs(z, source, 1 - defColor, graph, color) == true)
                    return true;
            }
            else {
                if (z != par && color[z] == defColor)
                    return true;
            }
        }

        return false;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (dfs(i, -1, 0, graph, color) == true)
                    return false;
            }
        }

        return true;
    }
};