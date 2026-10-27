class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> seen(graph.size(), 0);
        vector<int> answer;
        for(int i=0; i<graph.size(); i++){
            if(DFS(i, graph, seen)) answer.push_back(i);
        }
        return answer;
    }
    bool DFS(int ind, vector<vector<int>>& graph, vector<int>& seen){
        if(seen[ind]==1){
            return false;
        }
        if(seen[ind]==2) return true;
        seen[ind] = 1;
        bool to = true;
        for(int i=0; i<graph[ind].size(); i++){
            to = to && DFS(graph[ind][i], graph, seen);
            if(!to) return false;
        }
        seen[ind] = 2;
        return true;
    }
};