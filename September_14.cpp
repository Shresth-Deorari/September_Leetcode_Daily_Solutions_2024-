class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = 0;
        for(auto i : nums)maxi = max(maxi,i);
        int ans = 1;
        int temp = 0;
        cout<<maxi<<endl;
        for(int i  =0;i<nums.size();i++){
            if(temp==0 && nums[i]==maxi)temp=1;
            if(i>0 && nums[i-1]==maxi && nums[i]==maxi)temp++;
            ans = max(ans,temp);
            if(nums[i]!=maxi)temp = 0;
        }
        return ans;
    }
};