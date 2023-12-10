class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int n = batteryPercentages.size();
        int ans = 0;
        
        for(int i = 0; i < n; ++i)
        {
            if(batteryPercentages[i] - ans > 0)
                ans++;
        }
        
        return ans;
    }
};

auto speedup = cin.tie(NULL) -> sync_with_stdio(false);