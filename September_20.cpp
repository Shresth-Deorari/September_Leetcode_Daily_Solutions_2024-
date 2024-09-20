class Solution {
    vector<int> computeLPS(const string &s) {
        int n = s.size();
        vector<int> lps(n, 0);
        int len = 0;
        int i = 1;
        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string new_s = s + "#" + rev_s;
        vector<int> lps = computeLPS(new_s);
        int longest_palindrome_length = lps.back();
        string to_add = rev_s.substr(0, s.size() - longest_palindrome_length);
        return to_add + s;
    }
};
