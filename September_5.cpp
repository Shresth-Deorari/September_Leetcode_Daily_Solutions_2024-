class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = 0;
        for(auto i : rolls)m += i;
        int tot = mean * (n + rolls.size());
        int rem = tot - m;
        if(rem < n || rem > n*6)return {}; 
        int all = rem/n;
        vector<int>ans(n,all);
        rem = rem%n;
        for(int i = 0;i<n&&rem>0;i++){
            if(ans[i]<6){
                ans[i]++;
                rem--;
            }
        }
        return ans;
    }
};