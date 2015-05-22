/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval>::iterator it = intervals.begin();
        vector<Interval>::iterator del_it = intervals.begin();
        
        while (it != intervals.end()) {
            if (newInterval.end < it->start) {
                it = intervals.erase(del_it, it);
                intervals.insert(it, newInterval);
                return intervals;
            } else if (newInterval.start > it->end) {
                del_it = it + 1;
                it++;
            } else {
                newInterval.start = min(newInterval.start, it->start);
                newInterval.end = max(newInterval.end, it->end);
                it++;
            }
        }
        if (del_it != it) {
            intervals.erase(del_it, it);
        }
        intervals.insert(intervals.end(), newInterval);
        return intervals;
    }
};
