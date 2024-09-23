class Solution {
    int getmin(string &s,unordered_set<string>&st,int i,vector<int>&dp){
        if(i==s.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int mini = 1 + getmin(s,st,i+1,dp);
        
        string temp = "";
        for(int j = i;j<s.size();j++){
            temp += s[j];
            if(st.count(temp)){
                mini = min(mini,getmin(s,st,j+1,dp));
            }
        }
        return dp[i] = mini;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        unordered_set<string>st(dictionary.begin(),dictionary.end());
        vector<int>dp(n+1,-1);
        return getmin(s,st,0,dp);
    }
};