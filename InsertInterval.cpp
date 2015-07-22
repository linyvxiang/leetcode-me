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
        vector<Interval> ret;
        if (intervals.empty()) {
            ret.push_back(newInterval);
            return ret;
        }
        bool inserted = false;
        int i = 0;
        while (i < intervals.size()) {
            if (ret.empty()) {
                if (newInterval.start < intervals[i].start) {
                    ret.push_back(newInterval);
                    inserted = true;
                } else {
                    ret.push_back(intervals[i]);
                }
            } else if (!inserted && newInterval.start < intervals[i].start) {
                if (newInterval.start <= ret[ret.size() - 1].end) {
                    ret[ret.size() - 1].start = min(newInterval.start,
                                                    ret[ret.size() -1].start);
                    ret[ret.size() - 1].end = max(newInterval.end,
                                                    ret[ret.size() -1].end);
                } else {
                    ret.push_back(newInterval);
                }
                inserted = true;
            } else {
                if (intervals[i].start <= ret[ret.size() - 1].end){
                    ret[ret.size() - 1].start = min(intervals[i].start,
                                                    ret[ret.size() - 1].start);
                    ret[ret.size() - 1].end = max(intervals[i].end,
                                                    ret[ret.size() - 1].end);
                } else {
                    ret.push_back(intervals[i]);
                }
                i++;
            }
        }
        if (!inserted) {
            if (newInterval.start <= ret[ret.size() - 1].end) {
                ret[ret.size() - 1].start = min(newInterval.start,
                                                ret[ret.size() - 1].start);
                ret[ret.size() - 1].end = max(newInterval.end,
                                                ret[ret.size() - 1].end);
            } else {
                ret.push_back(newInterval);
            }
        }
        return ret;
    }
};
