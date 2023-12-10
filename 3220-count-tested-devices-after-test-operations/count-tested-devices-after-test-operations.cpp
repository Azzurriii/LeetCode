class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int n = batteryPercentages.size();
        int testedDevices = 0;

        for (int i = 0; i < n; i++) {
            if (batteryPercentages[i] > 0) {
                testedDevices++;
                for (int j = i + 1; j < n; j++) {
                    batteryPercentages[j] = max(0, batteryPercentages[j] - 1);
                }
            }
        }

        return testedDevices;
    }
};

auto speedup = cin.tie(NULL) -> sync_with_stdio(false);