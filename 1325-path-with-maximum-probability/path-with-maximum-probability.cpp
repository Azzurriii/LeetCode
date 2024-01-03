class Solution {
public:
    double Dijkstra(vector<pair<double,int>>adj[],int n,int u,int v){
        vector<double>dis(n+100,DBL_MIN);
        vector<bool>visited(n+100,false);
        dis[u]=1.0;
        priority_queue<pair<double,int>>pq;
        pq.push({1.0,u});
        while(!pq.empty()){
            pair<double,int>top=pq.top();
            pq.pop();
            int dinh=top.second;
            if(!visited[dinh]){
                visited[dinh]=true;
                for(auto x:adj[dinh]){
                    int dinhke=x.second;
                    double w=x.first;
                    if(dis[dinhke] < dis[dinh]*w){
                        dis[dinhke]=dis[dinh]*w;
                        pq.push({dis[dinhke],dinhke});
                    }
                }
            }
        }
        return dis[v];
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<double,int>>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({succProb[i],edges[i][1]});
            adj[edges[i][1]].push_back({succProb[i],edges[i][0]});

        }
        return Dijkstra(adj,n,start_node,end_node);
    }
};