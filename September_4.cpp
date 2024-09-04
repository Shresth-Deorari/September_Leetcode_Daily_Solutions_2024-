class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int, pair<int, int>> direction_change;
        direction_change[0] = {0, 1};    
        direction_change[1] = {1, 0};   
        direction_change[2] = {0, -1};   
        direction_change[3] = {-1, 0};   
        int direction = 0;
        int offset = 30000;
        unordered_set<long long> obs;

        for (auto i : obstacles) {
            obs.insert((i[0] + offset) + ((i[1] + offset) * 60001ll));  
        }

        int ans = 0;
        int x = 0, y = 0;

        for (auto it : commands) {
            if (it == -1) { 
                direction = (direction + 1) % 4;
            } else if (it == -2) {  
                direction = (direction - 1 + 4) % 4;
            } else {
                for (int i = 0; i < it; i++) {
                    int delx = direction_change[direction].first;
                    int dely = direction_change[direction].second;
                    int newx = x + delx;
                    int newy = y + dely;

                    if (obs.find((newx + offset) + ((newy + offset) * 60001)) != obs.end()) break;

                    x = newx;
                    y = newy;
                    int distance = x * x + y * y;
                    ans = max(ans, distance);
                }
            }
        }

        return ans;
    }
};
