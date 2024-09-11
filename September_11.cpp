class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorred = start^goal;
        int count = 0;
        while(xorred){
            if(xorred&1)count++;
            xorred = xorred>>1;
        }
        return count;
    }
};