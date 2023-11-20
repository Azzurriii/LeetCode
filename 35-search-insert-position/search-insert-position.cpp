class Solution {
private:
    int searchHelper(vector<int>& nums, int target, int left, int right){
        if(left <= right)
        {
            int mid = left + (right - left)/2;
            if(nums[mid] == target)
                return mid;
            else if(target < nums[mid])
                return searchHelper(nums, target, left, mid - 1);
            else
                return searchHelper(nums, target, mid + 1, right);
        }
        return left;
    }
public:
    int searchInsert(vector<int>& nums, int target) {
        return searchHelper(nums, target, 0, nums.size() - 1);
    }
};