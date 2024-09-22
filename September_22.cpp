class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        k--; 
        while (k > 0) {
            long long steps = countSteps(cur, n);
            if (steps <= k) {
                cur++;
                k -= steps;
            } else {
                cur *= 10;
                k--; 
            }
        }
        return cur;
    }

private:
    long long countSteps(int cur, int n) {
        long long steps = 0;
        long long first = cur;
        long long last = cur;

        while (first <= n) {
            steps += min((long long)n + 1, last + 1) - first;
            first *= 10;
            last = last * 10 + 9;
        }
        return steps;
    }
};
