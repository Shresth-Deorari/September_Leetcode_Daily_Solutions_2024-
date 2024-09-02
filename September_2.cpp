class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        
        vector<long long> prefixSum(n);
        prefixSum[0] = chalk[0];
        for (int i = 1; i < n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + chalk[i];
        }
        
        k %= prefixSum.back(); 
        
        auto it = upper_bound(prefixSum.begin(), prefixSum.end(), k);
        return it - prefixSum.begin();
    }
};
