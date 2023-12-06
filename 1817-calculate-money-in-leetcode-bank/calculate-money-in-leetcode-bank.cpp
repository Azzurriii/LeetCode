class Solution {
public:
    int totalMoney(int n) {
        int numOfFullWeek = n / 7;
        int firstFullWeek = 28;
        int lastFullWeek = 28 + (numOfFullWeek - 1) * 7;
        int moneyOfFullWeek = numOfFullWeek * (firstFullWeek + lastFullWeek) / 2;
        
        int monday = 1 + numOfFullWeek;
        int finalWeek = 0;
        for (int dayLeft = 0; dayLeft < n % 7; dayLeft++) {
            finalWeek += monday + dayLeft;
        }
        
        return moneyOfFullWeek + finalWeek;
    }
};