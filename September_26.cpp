class MyCalendar {
    vector<pair<int,int>>events;
    // unordered_map<int,int>mp;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        int n = events.size();
        if(n==0){
            events.push_back({start,end});
            return true;
        }
        if(events[0].first >= end){
            events.insert(events.begin(),{start,end});
            return true;
        }
        if(events[n-1].second <= start){
            events.push_back({start,end});
            return true;
        }
        for(int i = 0;i<n-1;i++){
            if(events[i].second<=start && events[i+1].first>=end){
                events.insert(events.begin() + i+1,{start,end});
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */