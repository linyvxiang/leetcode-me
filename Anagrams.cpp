class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> umap;
        int i;
        for(i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            umap[temp].push_back(strs[i]);
        }
        vector<string> res;
        for(auto it = umap.begin(); it != umap.end(); it++) {
            if(it->second.size() > 1)
                res.insert(res.end(), it->second.begin(), it->second.end());
        }
        return res;
    }
};
