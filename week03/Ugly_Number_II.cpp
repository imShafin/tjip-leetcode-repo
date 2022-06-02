//TC : O(NlogN)
//MC : O(N)

class Solution {
public:
    set<int> uglynums;
    vector<long long> pow2, pow3, pow5;
    void generatePow(int n, vector<long long>& nums) {
        long long res = 1;
        for(int i = 1; i < 33; i++) {
            if (res*n < INT_MAX) {
                uglynums.insert(res*=n);
                nums.push_back(res);
            }
            else break;
        }
    }
    void generateUglynums() {
        for (int i = 0; i < pow2.size(); i++) {
            for (int j = 0; j < pow3.size(); j++) {
                for (int k = 0; k < pow5.size(); k++) {
                    if ( pow2[i] * pow5[k] < INT_MAX ) uglynums.insert(pow2[i] * pow5[k]);
                    if ( pow2[i] * pow3[j] < INT_MAX ) uglynums.insert(pow2[i] * pow3[j]);
                    if ( pow3[j] * pow5[k] < INT_MAX ) uglynums.insert(pow3[j] * pow5[k]);
                    if ( pow2[i] * pow3[j] * pow5[k] < INT_MAX ) uglynums.insert(pow2[i] * pow3[j] * pow5[k]);
                    else break;
                }
            }
        }
    }
    int nthUglyNumber(int n) {
        uglynums.insert(1);
        generatePow (2, pow2);
        generatePow (3, pow3);
        generatePow (5, pow5);
        generateUglynums();
        int cnt = 0;
        for (set<int>::iterator it = uglynums.begin(); it != uglynums.end(); ++it) {
            cnt++;
            if(cnt == n) return *it;
        }
        return 0;
    }
};
