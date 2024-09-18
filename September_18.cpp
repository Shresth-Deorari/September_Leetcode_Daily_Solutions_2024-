class Solution {
    static bool comp(string &a, string &b) {
        return a + b > b + a; 
    }

public:
    string largestNumber(vector<int>& num) {
        int n = num.size();
        vector<string> nums(n);
        for (int i = 0; i < n; i++) {
            nums[i] = to_string(num[i]);
        }
        sort(nums.begin(), nums.end(), comp);

        if (nums[0] == "0") {
            return "0";
        }

        string ans;
        for (const auto &i : nums) {
            ans += i;
        }
        return ans;
    }
};
