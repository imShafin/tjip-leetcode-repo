/// TC: O(2^N)   --> N is the length of nums array.
/// MC: O(M)     --> M is total length of all subsets.
class Solution {
public:
    vector<vector<int>> allSubsets;
    void genAllSubsets(int curr, vector<int> subset, vector<int>& nums)
    {
      if(curr == nums.size())
      {
        allSubsets.push_back(subset);
        return;
      }
      subset.push_back(nums[curr]);
      genAllSubsets(curr + 1, subset, nums);
      subset.pop_back();
      genAllSubsets(curr + 1, subset, nums);
      ///subset.push_back(nums[curr]);
      ///genAllSubsets(curr + 1, subset, nums);
      ///subset.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        ///vector<vector<int>> allSubsets;
        int n = nums.size();
        genAllSubsets(0, {}, nums);
        return allSubsets;
    }
};
