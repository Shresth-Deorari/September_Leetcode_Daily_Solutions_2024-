class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int>mp;
        int i = 0;
        string word = "";
        while(i<s1.size()){
            if(s1[i]==' '){
                mp[word]++;
                word = "";
            }
            else
            word += s1[i];
            i++;
        }
        mp[word]++;
        i = 0;
        word = "";
        while(i<s2.size()){
            if(s2[i]==' '){
                mp[word]++;
                word = "";
            }
            else
            word += s2[i];
            i++;
        }
        mp[word]++;
        vector<string>ans;
        for(auto i : mp)if(i.second==1)ans.push_back(i.first);
        return ans;
    }
};