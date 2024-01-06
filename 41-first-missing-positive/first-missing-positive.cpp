class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> map;
        for(int i: nums){
            if(i > 0) {
                map[i]++;
            }
        }
        for(int i = 1; i <= n; i++){
            if(map.find(i) == map.end()){
                return i;
            }
        }
        return n + 1;
    }
};
