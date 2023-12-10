class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = 0, i = 0, j = 0, n = nums.size();
        unordered_map<int,int> m;
        long long ans = 0;
        
        for(auto it : nums) { //find max element
            maxi = max(maxi,it);
        }
        
        while(i < nums.size())
        {
            m[nums[i]]++; //include current element
            while(m[maxi] >= k) //if current window has more than 'k' maxi
            {
                ans += (n-i); //then, there are (n-i) such subarrays: nums[j,i], nums[j,i+1], nums[j,i+2],........, nums[j,n-1]
                if(--m[nums[j]] == 0) //start removing from the start
                    m.erase(nums[j]);
                j++;
            }
            i++;
        }
     return ans;
    }
};