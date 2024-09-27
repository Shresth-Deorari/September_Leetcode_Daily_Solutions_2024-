class MyCalendarTwo {
    vector<pair<int, int>> events;      
    vector<pair<int, int>> overlaps;    

public:
    MyCalendarTwo() { }

    bool book(int start, int end) {
        for (auto& event : overlaps) {
            if (max(event.first, start) < min(event.second, end)) {
                return false;
            }
        }
        for (auto& event : events) {
            if (max(event.first, start) < min(event.second, end)) {
                overlaps.push_back({max(event.first, start), min(event.second, end)});
            }
        }
        events.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
