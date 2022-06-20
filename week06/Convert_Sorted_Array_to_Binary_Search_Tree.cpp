/// TC: O(NlogN) /// N = Size of nums array
/// MC: O(T) T means per recursion call
class Solution {
public:
    TreeNode* BST(vector<int>& nums, int L, int R)
    {
      if (L > R) return NULL;
      int M = L + (R - L) / 2;
      TreeNode* curr = new TreeNode(nums[M]);;
      curr -> left = BST(nums, L, M - 1);
      curr -> right = BST(nums, M + 1, R);
      return curr;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      return BST(nums, 0, nums.size() - 1);
    }
};
