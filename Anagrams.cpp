class Solution {
    public:
        vector<string> anagrams(vector<string> &strs) {
            unordered_map<string, vector<string> > umap;
            vector<string> ret;
            for(int i = 0; i < strs.size(); i++) {
                string temp = strs[i];
                sort(temp.begin(), temp.end());
                umap[temp].push_back(strs[i]);
            }
            for(auto i = umap.begin(); i != umap.end(); i++) {
                if(i->second.size() > 1)
                    ret.insert(ret.end(), i->second.begin(), i->second().end());
            }
            return  ret;
        }
};
