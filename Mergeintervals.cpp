/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp(Interval a, Interval b)
{
    if(a.start != b.start)
        return a.start < b.start;
    return a.end < b.end;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        sort(intervals.begin(), intervals.end(), cmp);

        vector<Interval>::iterator it = intervals.begin();
        while(it != intervals.end()) {
            if(res.size() == 0) {
                res.push_back(*it);
            } else if(res.back().end >= it->start || res.back().start == it->start) {
                res.back().end = max(it->end, res.back().end);
            } else {
                res.push_back(*it);
            }
            it++;
        }
        return res;
    }
};
