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
        int cur_pos = 0, pre_pos = -1;
        for(; cur_pos < intervals.size(); cur_pos++) {
            if(intervals[cur_pos].start >= newInterval.start)
                break;
            pre_pos = cur_pos;
        }
        
        if(pre_pos >= 0 && cur_pos != intervals.size()) { //find a pos in the middle
            if(intervals[pre_pos].end > newInterval.start) {
                intervals[pre_pos].end = max(newInterval.end, intervals[pre_pos].end);
                while(check_merge(pre_pos, intervals))
                    do_merge(pre_pos, intervals);
            } else if(intervals[pre_pos].end < newInterval.start) {
                intervals.insert(intervals.begin() + pre_pos, newInterval);
                while(check_merge(pre_pos + 1, intervals))
                    do_merge(pre_pos + 1, intervals);
            }

        } else if(cur_pos == 0) {
            intervals.insert(intervals.begin(), newInterval);
            while(check_merge(0, intervals))
                do_merge(0, intervals);
        } else if(cur_pos == intervals.size()) {
            intervals.insert(intervals.end(), newInterval);
            while(intervals.size() > 1 && check_merge(intervals.size() - 2, intervals))
                do_merge(intervals.size() - 2, intervals);
        }
        return intervals;
    }
private:
    bool check_merge(int cp, vector<Interval> &intervals)
    {
        return cp != intervals.size() - 1 &&
            intervals[cp].end >= intervals[cp + 1].start;
    }
    void do_merge(int cp, vector<Interval> &intervals)
    {
        if(intervals[cp].end <= intervals[cp + 1].end) {
            intervals[cp].end = intervals[cp + 1].end;
            intervals.erase(intervals.begin() + cp + 1);
        } else {
            intervals.erase(intervals.begin() + cp + 1);
        }
    }
};
