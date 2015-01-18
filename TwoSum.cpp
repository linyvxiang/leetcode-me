struct pos_num {
    int old_pos;
    int val;
    pos_num(int p, int v) : old_pos(p), val(v) {}
};
bool cmp(const pos_num &A, const pos_num &B)
{
   return A.val < B.val;
} 
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<pos_num> trans_num;
        for(int i = 0; i < numbers.size(); i++) {
            trans_num.push_back(pos_num(i + 1, numbers[i]));
        }
        sort(trans_num.begin(), trans_num.end(), cmp);
        int start = 0, end = trans_num.size() - 1;
        vector<int> ret;
        while(start < end) {
            if(trans_num[start].val + trans_num[end].val == target)
                break;
            else if(trans_num[start].val + trans_num[end].val < target)
                start++;
            else
                end--;
        }
        ret.push_back(trans_num[start].old_pos);
        ret.push_back(trans_num[end].old_pos);
        sort(ret.begin(), ret.end());
        return ret;
    }
};
