class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        if(height.size() == 0)
            return 0;
        int maxLeft = INT_MIN, maxRight = INT_MIN;
        int ans = 0;
        while(left < right){
            maxLeft = max(maxLeft, height[left]);
            maxRight = max(maxRight, height[right]);
            ans += (maxLeft<maxRight) ? maxLeft - height[left++] : maxRight - height[right--];
        }
        return ans;
    }
};