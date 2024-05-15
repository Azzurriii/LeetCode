class Solution {
private:
void countingSort(std::vector<int> &arr)
{
    int maxVal = *std::max_element(arr.begin(), arr.end());
    int minVal = *std::min_element(arr.begin(), arr.end());
    int range = maxVal - minVal + 1;

    std::vector<int> count(range, 0);
    std::vector<int> output(arr.size());
    for (int i = 0; i < arr.size(); i++)
    {
        count[arr[i] - minVal]++;
    }
    for (int i = 1; i < count.size(); i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = output[i];
    }
}
public:
    void sortColors(vector<int>& nums) {
        countingSort(nums);
    }
};