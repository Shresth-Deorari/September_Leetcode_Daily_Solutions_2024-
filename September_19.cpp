class Solution {
        vector<int> computeWays(const string &expression, int i, int j) {
        vector<int> results;
        for (int k = i; k <= j; ++k) {
            if (expression[k] == '+' || expression[k] == '-' || expression[k] == '*') {
                vector<int> leftResults = computeWays(expression, i, k - 1);
                vector<int> rightResults = computeWays(expression, k + 1, j);

                for (int left : leftResults) {
                    for (int right : rightResults) {
                        if (expression[k] == '+') {
                            results.push_back(left + right);
                        } else if (expression[k] == '-') {
                            results.push_back(left - right);
                        } else if (expression[k] == '*') {
                            results.push_back(left * right);
                        }
                    }
                }
            }
        }
        if (results.empty()) {
            results.push_back(stoi(expression.substr(i, j - i + 1)));
        }

        return results;
    }

public:
    vector<int> diffWaysToCompute(string expression) {
        return computeWays(expression, 0, expression.size() - 1);
    }
};
