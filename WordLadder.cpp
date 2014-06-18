class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        int cur_steps = 0, cur_num = 1, res = -1, next_num = 0;
        queue<string> Q;
        unordered_set<string>::iterator it;
        unordered_set<string> visited;
        Q.push(start);
        while(!Q.empty()) {
            string tmp = Q.front();
            Q.pop();
            if(judge_string(tmp, end)) {
                res = (cur_num == 0 ? cur_steps + 1 : cur_steps) + 2;
                break;
            }
            for(it = dict.begin(); it != dict.end(); it++) {
                if(visited.find(*it) == dict.end() && judge_string(tmp, (string)(*it))) {
                    Q.push(*it);
                    visited.insert(*it);
                    next_num++;
                }
            }
            cur_num--;
            if(cur_num == 0) {
                cur_num = next_num;
                next_num = 0;
                cur_steps++;
            }

        }
        return res;
    }
private:
    int judge_string(string &src, string dst)
    {
        int i, count = 0;
        for(i = 0; i < src.size(); i++) {
            if(src[i] != dst[i]) {
                count++;
                if(count > 1)
                    break;
            }
        }
        return count == 1;
    }
};
