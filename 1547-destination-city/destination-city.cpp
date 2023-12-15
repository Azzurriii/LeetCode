class Solution {
public:
    string destCity(vector<vector<string>> &path){
        unordered_map<string, string> m;

        for (int i = 0; i < path.size(); i++)
            m[path[i][0]] = path[i][1];

        string start = path[0][0];

        while (m.find(start) != m.end())
            start = m[start];
            
        return start;
    }
};