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
    static bool cmp(const Interval& inter_a, const Interval& inter_b) {
        if (inter_a.start != inter_b.start) {
            return inter_a.start < inter_b.start;
        } else {
            return inter_a.end < inter_b.end;
        }
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ret;
        if (intervals.empty()) {
            return ret;
        }
        ret.reserve(intervals.size());
        sort(intervals.begin(), intervals.end(), cmp);
        for (int i = 0; i < intervals.size(); i++) {
            if (ret.empty() || intervals[i].start > ret[ret.size() - 1].end) {
                ret.push_back(intervals[i]);
            } else {
                ret[ret.size() -1].end = max(ret[ret.size() - 1].end, intervals[i].end);
            }
        }
        return ret;
    }
};
