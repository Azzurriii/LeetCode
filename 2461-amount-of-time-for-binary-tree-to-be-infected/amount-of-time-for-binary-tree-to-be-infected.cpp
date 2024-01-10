/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void buildGraph(TreeNode* node, unordered_map<int, vector<int>>& graph) {
        if (!node) {
            return;
        }
        
        if (node->left) {
            graph[node->val].push_back(node->left->val);
            graph[node->left->val].push_back(node->val);
            buildGraph(node->left, graph);
        }
        
        if (node->right) {
            graph[node->val].push_back(node->right->val);
            graph[node->right->val].push_back(node->val);
            buildGraph(node->right, graph);
        }
    }

    int bfs(int start, unordered_map<int, vector<int>>& graph) {
        int ans = 0;
        queue<pair<int, int>> q;
        unordered_set<int> infected;
        
        q.push({start, 0});
        infected.insert(start);
        
        while (!q.empty()) {
            int node = q.front().first;
            int currentTime = q.front().second;
            q.pop();
            
            ans = max(ans, currentTime);
            
            for (int neighbor : graph[node]) {
                if (infected.count(neighbor) == 0) {
                    q.push({neighbor, currentTime + 1});
                    infected.insert(neighbor);
                }
            }
        }
        
        return ans;
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> graph;
        buildGraph(root, graph);
        return bfs(start, graph);
    }

};
auto speedup = cin.tie(NULL) -> sync_with_stdio(false);