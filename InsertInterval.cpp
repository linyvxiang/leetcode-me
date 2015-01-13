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
        int len = intervals.size(), i = 0;
        bool flag = false;
        vector<Interval> ret;
        if(intervals.empty() || newInterval.end < intervals[0].start) {
            ret.push_back(newInterval);
            flag = true;
        }
        while(i < len) {
            if(flag) {
                ret.push_back(intervals[i]);
                i++;
                continue;
            }
            if(intervals[i].end < newInterval.start) {
                ret.push_back(intervals[i]);
                i++;
            } else {
                if(newInterval.end < intervals[i].start) {
                    ret.push_back(newInterval);
                    flag = true;
                    continue;
                }
                Interval tmp(min(intervals[i].start, newInterval.start),
                                max(intervals[i].end, newInterval.end));
                i++;
                while(i < len && tmp.end >= intervals[i].start) {
                    tmp.start = min(tmp.start, intervals[i].start);
                    tmp.end = max(tmp.end, intervals[i].end);
                    i++;
                }
                ret.push_back(tmp);
                flag = true;
            }
        }
        if(!flag)
            ret.push_back(newInterval);
        return ret;
    }
};
