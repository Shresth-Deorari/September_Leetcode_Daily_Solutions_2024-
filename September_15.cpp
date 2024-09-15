class Solution {
public:
    int findTheLongestSubstring(string s) {
        int ans = 0;
        int mask = 0;
        unordered_map<int,int>hashTable;
        hashTable[0] = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i]=='a'){
                mask = mask^(1<<4);
            }
            if(s[i]=='e'){
                mask = mask^(1<<3);
            }
            if(s[i]=='i'){
                mask = mask^(1<<2);
            }
            if(s[i]=='o'){
                mask = mask^(1<<1);
            }
            if(s[i]=='u'){
                mask = mask^(1<<0);
            }
            if(hashTable.find(mask)!=hashTable.end()){
                ans = max(ans,i-hashTable[mask]+1);
            }
            else{
                hashTable[mask] = i+1;
            }
        }
        return ans;
    }
};