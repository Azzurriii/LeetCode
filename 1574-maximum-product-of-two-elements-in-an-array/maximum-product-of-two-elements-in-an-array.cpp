class Solution {
public:
    int maxProduct(vector<int>& nums) {
        auto it = std::max_element(nums.begin(), nums.end());
        int x=*it-1;
        nums.erase(it);  
        auto yt = std::max_element(nums.begin(), nums.end());
        cout<<*yt<<endl;
        return (x) * (*yt - 1);
    }
};