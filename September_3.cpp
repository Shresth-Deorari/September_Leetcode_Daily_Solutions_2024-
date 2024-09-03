class Solution {
public:
    int getLucky(string str, int k) {
        int sum = 0;
        string m ;
        for(auto i: str){
                m += to_string(i-'a'+1) ;
            }
        str = m;
        while(k--){
            sum = 0;
            for(auto i : str){
                sum += i - '0' ;
            }
            str = to_string(sum);
        }
        return sum;
    }
};