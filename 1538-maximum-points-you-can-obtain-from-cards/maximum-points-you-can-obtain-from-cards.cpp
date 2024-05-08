class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int totalPts = 0;
        for(int i = 0; i < k; i++){
            totalPts += cardPoints[i];
        }
        int windowSize = n - k;
        int curr = totalPts;
        for(int i = k - 1; i >= 0; i--){
            curr -= cardPoints[i];
            curr += cardPoints[n - k + i];
            
            totalPts = max(totalPts, curr);
        }
        return totalPts;
    }   
};