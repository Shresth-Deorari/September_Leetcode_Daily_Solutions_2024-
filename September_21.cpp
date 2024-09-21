class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for (int i = 1; i <= 9; i++) {
            dfs(i, n, ans);
        }
        return ans;
    }
    void dfs(int cur, int n, vector<int>& ans) {
        if (cur > n) return; 
        ans.push_back(cur);
        for (int i = 0; i <= 9; i++) {
            int next = cur * 10 + i;
            if (next > n) break;  
            dfs(next, n, ans); 
        }
    }
};
