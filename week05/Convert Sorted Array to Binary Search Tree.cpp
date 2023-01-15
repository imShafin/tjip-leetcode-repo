/// TC: O(NlogN) /// N is the Size of nums array
/// MC: O(D)     /// D = 
class Solution {
public:
    TreeNode* makeBST(vector<int>& nums, int L, int R)
    {
      if (L > R) return NULL;
      int M = L + (R - L) / 2;
      TreeNode* head = new TreeNode(nums[M]);;
      head -> left = makeBST(nums, L, M - 1);
      head -> right = makeBST(nums, M + 1, R);
      return head;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      return makeBST(nums, 0, nums.size() - 1);
    }
};