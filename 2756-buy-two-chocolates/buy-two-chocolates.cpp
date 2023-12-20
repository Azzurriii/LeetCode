class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        return (money - (prices[0]+prices[1]) < 0) ? money : (money-(prices[0]+prices[1]));
    }
};
auto speedup = cin.tie(nullptr) -> sync_with_stdio(false);