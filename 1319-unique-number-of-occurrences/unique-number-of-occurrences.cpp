class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr){
        unordered_map<int, int> count;
        for(int i = 0; i < arr.size(); i++){
            count[arr[i]]++;
        }
        unordered_set<int> s;
        for(auto it = count.begin(); it != count.end(); it++){
            if(s.count(it->second) != 0){
                return false;
            }
            s.insert(it->second);
        }
        return true;
    }
};