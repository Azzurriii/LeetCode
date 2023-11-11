class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numToIndex;

        for(int i=0;i<nums.size();++i){
            int comp=target-nums[i];
            if(numToIndex.find(comp)!=numToIndex.end()){
                return {numToIndex[comp], i};
            }
            numToIndex[nums[i]] = i;
        }
        return {};
    }
};