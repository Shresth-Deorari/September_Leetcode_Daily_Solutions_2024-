class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int>prexor(n,0);
        prexor[0] = arr[0];
        for(int i = 1;i<n;i++){
            prexor[i] = prexor[i-1]^arr[i];
        }
        vector<int>ans;
        // for(auto i : prexor)cout<<i<<endl;
        for(auto i : queries){
            int l = i[0];
            int r = i[1];
            if(l==0)ans.push_back(prexor[r]);
            else ans.push_back(prexor[r]^prexor[l-1]);
        }
        return ans;
    }
};