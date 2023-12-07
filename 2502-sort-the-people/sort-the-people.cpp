class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        //map height[i] to names[i]
        unordered_map<int, string> mpp;
        for(int i=0; i<heights.size(); i++){
            mpp[heights[i]] = names[i];    
        }
        
        vector<string> res;
        sort(heights.begin(), heights.end(), greater<int>());
        
        for(auto it: heights)
            res.push_back(mpp[it]);
        
        return res;
    }
};