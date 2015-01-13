/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp(const Interval &a, const Interval &b)
{
    if(a.start != b.start)
        return a.start < b.start;
    return a.end < b.end;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        int len = intervals.size(), i = 0;
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> ret;
        while(i < len) {
            if(ret.empty()) {
                ret.push_back(intervals[i]);
                i++;
            } else {
                if(intervals[i].start <= (*ret.rbegin()).end) {
                    (*ret.rbegin()).end = max((*ret.rbegin()).end,
                                                intervals[i].end);
                    i++;
                } else {
                    ret.push_back(intervals[i]);
                    i++;
                }
            }
        }
        return ret;
    }
};
