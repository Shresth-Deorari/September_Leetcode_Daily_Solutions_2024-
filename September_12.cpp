class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool>all(26,0);
        int ans = 0;
        for(auto i : allowed)if(all[i-'a']==0)all[i-'a']=1;
        for(auto i : words){
            bool valid = true;
            for(auto j : i){
                if(all[j-'a']==0){
                    valid = false;
                    break;
                }
            }
            if(valid)ans++;
        }
        return ans;
    }
};