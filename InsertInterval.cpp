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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval>::iterator it = intervals.begin();
        vector<Interval>::iterator del_start = intervals.begin();
        while(it != intervals.end()) {
            if(newInterval.end < it->start) {
                if(del_start != it)
                    it = intervals.erase(del_start, it);
                intervals.insert(it, newInterval);
                return intervals;
            }
            if(it->end < newInterval.start) {
                del_start = it + 1;
                it++;
            } else {
                newInterval.start = min(it->start, newInterval.start);
                newInterval.end = max(it->end, newInterval.end);
                it++;
            }
        }
        if(del_start != it)
            intervals.erase(del_start, it);
        intervals.insert(intervals.end(), newInterval);
        return intervals;
    }
};
