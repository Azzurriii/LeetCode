class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node){
        vector<vector<pair<int, double>>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<double> prob(n, 0);
        prob[start_node] = 1;
        priority_queue<pair<double, int>> pq;
        pq.push({1, start_node});
        while(!pq.empty()){
            pair<double, int> tmp = pq.top();
            pq.pop();
            int u = tmp.second;
            for(auto neighbor: adj[u]){
                int v = neighbor.first;
                double weight = neighbor.second;
                if(prob[v] < prob[u] * weight){
                    prob[v] = prob[u] * weight;
                    pq.push({prob[v], v});
                }
            }
        }
        return prob[end_node];
    }
};