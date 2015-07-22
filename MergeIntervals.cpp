class Solution {
public:
    static bool cmp(Interval& a, Interval& b) {
        if (a.start != b.start) {
            return a.start < b.start;
        }
        return a.end < b.end;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ret;
        if (intervals.empty()) {
            return ret;
        }
        sort(intervals.begin(),intervals.end(), cmp);
        ret.push_back(intervals[0]);
        int cur_size = 1;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start <= ret[cur_size - 1].end ||
                    intervals[i].end <= ret[cur_size - 1].end) {
                ret[cur_size - 1].start = min(ret[cur_size - 1].start,
                                            intervals[i].start);
                ret[cur_size - 1].end = max(ret[cur_size - 1].end,
                                            intervals[i].end);
            } else {
                ret.push_back(intervals[i]);
                cur_size++;
            }
        }
        return ret;
    }
};
