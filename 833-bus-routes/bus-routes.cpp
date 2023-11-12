class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target)
            return 0;
        
        unordered_map<int, vector<int>> graph;
        int routesLength = routes.size();
        unordered_set<int> seen;
        unordered_set<int> targets;
        queue<pair<int, int>> q;
        
        for (int i = 0; i < routesLength; i++) {
            sort(routes[i].begin(), routes[i].end());
            graph[i] = vector<int>();
        }
        
        for (int i = 0; i < routesLength; i++) {
            for (int j = i + 1; j < routesLength; j++) {
                if (intersect(routes[i], routes[j])) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        
        for (int i = 0; i < routesLength; i++) {
            if (existed(routes[i], source)) {
                seen.insert(i);
                q.push(make_pair(i, 0));
            }
            if (existed(routes[i], target)) {
                targets.insert(i);
            }
        }
        
        while (!q.empty()) {
            pair<int, int> item = q.front();
            q.pop();
            
            if (targets.count(item.first) > 0)
                return item.second + 1;
            
            for (int neighbor : graph[item.first]) {
                if (seen.count(neighbor) > 0)
                    continue;
                
                seen.insert(neighbor);
                q.push(make_pair(neighbor, item.second + 1));
            }
        }
        
        return -1;
    }
    
private:
    bool intersect(vector<int>& routeA, vector<int>& routeB) {
        int i = 0;
        int j = 0;
        
        while (i < routeA.size() && j < routeB.size()) {
            if (routeA[i] == routeB[j])
                return true;
            else if (routeA[i] < routeB[j]) {
                i++;
            } else {
                j++;
            }
        }
        
        return false;
    }
    
    bool existed(vector<int>& route, int target) {
        int left = 0;
        int right = route.size() - 1;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            
            if (route[mid] == target)
                return true;
            else if (route[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return false;
    }
};