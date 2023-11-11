class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
    int n = nums1.size();
    int m = nums2.size();

    int i = 0;
    int j = 0;
    int lastIndex = -1;

    vector<int> v(n + m, 0);

    while (i < n && j < m)
    {
        (nums1[i] <= nums2[j]) ? (v[++lastIndex] = nums1[i++]):(v[++lastIndex] = nums2[j++]);
    }

    while (i < n)
    {
        v[++lastIndex] = nums1[i++];
    }

    while (j < m)
    {
        v[++lastIndex] = nums2[j++];
    }

    int size = n + m;
    return (size % 2 == 0) ? (v[size / 2] + v[size / 2 - 1]) / 2.0 : (v[size / 2]);
    }
};