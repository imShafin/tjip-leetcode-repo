// TC: O(M + N)
// MC: O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = (m + n) - 1;
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] < nums2[j])
            {
                nums1[k--] = nums2[j--];
            }
            else nums1[k--] = nums1[i--];
        }
        for(k = j; k >= 0; k--) nums1[k] = nums2[j--];
    }
};
