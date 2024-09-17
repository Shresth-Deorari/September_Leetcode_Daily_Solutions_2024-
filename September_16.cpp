class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int>time(n);
        for(int i = 0;i<n;i++){
            int hour = stoi(timePoints[i].substr(0,2));
            int minutes = stoi(timePoints[i].substr(3,2));
            time[i] = 60*hour + minutes;
        }
        sort(time.begin(),time.end());
        int mini = INT_MAX;
        for(int i = 0;i<n-1;i++){
            mini = min(mini,abs(time[i+1]-time[i]));
        }
        mini = min(mini,abs(1440-time[n-1]+time[0]));
        return mini;
    }
};