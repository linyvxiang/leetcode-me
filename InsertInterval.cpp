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
private:
    static bool comp(Interval a, Interval b)
    {
        return a.start < b.start;
    }
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        //��ԭʼ�����ϲ���
        vector<Interval>::iterator ite = lower_bound(intervals.begin(),intervals.end(), newInterval, comp);//����startֵ���ֲ���
        if(ite != intervals.begin() && newInterval.start <= (ite-1)->end)//ite����һ������Ҳ���ܲ���ϲ�
        {
            ite--;
            //�ϲ�������������ֻ�͵�һ���ϲ��������йأ���Ϊ����ʱ��������������
            newInterval.start = min(newInterval.start, ite->start);
        }
        vector<Interval>::iterator eraseBegin = ite;
        for(; ite != intervals.end() && newInterval.end >= ite->start; ite++)
            if(newInterval.end < ite->end)newInterval.end = ite->end;//�ϲ��������������newInterval
			
			ite = intervals.erase(eraseBegin, ite);//[eraseBegin, ite)�Ǻϲ�ʱӦ��ɾ��������
			intervals.insert(ite, newInterval);//����ϲ��������
			return intervals;
    }
};
