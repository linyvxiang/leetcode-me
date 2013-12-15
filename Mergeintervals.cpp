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
       int len = intervals.size();
       vector<Interval> res;
       if(!len)
            return res;
       sort(intervals.begin(), intervals.end(), cmp);
       int i;
       res.push_back(intervals[0]);
       for(i = 1; i < len; i++) {
           if(res.back().start == intervals[i].start) {
               res.back().end = intervals[i].end;
           } else if(res.back().end >= intervals[i].start && intervals[i].end > res.back().end) {
               res.back().end = intervals[i].end;
           } else if(intervals[i].start > res.back().end) {
               res.push_back(intervals[i]);
           }
       }
       return move(res);
    }
};
