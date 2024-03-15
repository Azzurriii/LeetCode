class Solution {
    public int[] productExceptSelf(int[] nums) {
    int n = nums.length;
    int[] ans = new int[n];

    int leftProd = 1, rightProd = 1;

    for (int i = 0; i < n; i++) {
        ans[i] = leftProd;
        leftProd *= nums[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        ans[i] *= rightProd;
        rightProd *= nums[i];
    }

    return ans;
}
}