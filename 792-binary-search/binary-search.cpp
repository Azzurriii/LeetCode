class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearchHelper(nums, 0, nums.size() - 1, target);
    }

    int binarySearchHelper(vector<int>& nums, int left, int right, int target)
    {
        if(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target)
                return mid;
            else if(target < nums[mid])
                return binarySearchHelper(nums, left, mid - 1, target);
            else
                return binarySearchHelper(nums, mid + 1, right, target);
        }

        return -1;
        
    }
};