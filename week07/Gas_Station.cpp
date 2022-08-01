// TC: O(N)     N is the total number of Gas stations
// MC: O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int N = gas.size(), start = 0, prevGas = 0, currGas = 0;
      for (int i = 0; i < N; i++)
      {
        currGas += (gas[i] - cost[i]);
        if(currGas < 0)
        {
          start = i + 1;
          prevGas += currGas;
          currGas = 0;
        }
      }
      if (prevGas + currGas >= 0) return start;
      return -1;
    }
};
