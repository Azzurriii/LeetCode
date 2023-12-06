class Solution {
public:
    int totalMoney(int n) {
        int fullWeek = n / 7;
        int first = 28;
        int last = 28 + (fullWeek - 1) * 7;
        int moneyOfFullWeek = fullWeek * (first + last) / 2;
        
        int monday = 1 + fullWeek;
        int finalWeek = 0;
        for (int day = 0; day < n % 7; day++) {
            finalWeek += monday + day;
        }
        
        return moneyOfFullWeek + finalWeek;
    }
};