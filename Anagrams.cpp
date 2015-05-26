class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> ret;
        unordered_map<string, vector<string> > groups;
        for (int i = 0; i < strs.size(); i++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            groups[tmp].push_back(strs[i]);
        }
        unordered_map<string, vector<string> >::iterator it = groups.begin();
        while (it != groups.end()) {
            if (it->second.size() > 1) {
                ret.insert(ret.end(), it->second.begin(), it->second.end());
            }
            ++it;
        }
        return ret;
    }
};
