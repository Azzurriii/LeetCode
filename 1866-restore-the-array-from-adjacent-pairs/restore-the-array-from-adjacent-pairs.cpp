class Solution {
    struct Edge {
        int cnt{};
        int v[2]{};
        void addVertex(int u) { v[cnt++] = u; }
    };
    struct Neighbors {
        int cnt{};
        int v[2]{};
        int w[2]{};
        void addNeighbor(int u, int w) { v[cnt] = u; this->w[cnt++] = w; }
        pair<int, int> get(int uprev) const {
            if (v[0] != uprev) return {v[0], w[0]};
            return {v[1], w[1]};
        }
    };
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, Edge> edges;
        int V = 0;
        for (auto& p : adjacentPairs) {
            edges[p[0]].addVertex(V);
            edges[p[1]].addVertex(V++);
        }
        vector<Neighbors> adj(V);
        vector<int> res(V + 1);
        int i = 1;
        int u = -1;
        for (auto& [w, e] : edges) {
            if (e.cnt == 1) { u = e.v[0]; res[i--] = w; continue; }
            adj[e.v[0]].addNeighbor(e.v[1], w);
            adj[e.v[1]].addNeighbor(e.v[0], w);
        }
        res.back() = res[1];
        for (int uprev = -1, i = 1; i < V; ++i) {
            auto [unext, wnext] = adj[u].get(uprev);
            res[i] = wnext;
            uprev = exchange(u, unext);
        }
        return res;
    }
};